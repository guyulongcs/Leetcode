#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

#include <algorithm>

using namespace std;

typedef long long ll;
//SegmengTree Node
class SegmentNode {
public:
    ll s;
    ll e;
    ll cov;
    SegmentNode * left;
    SegmentNode * right;
    SegmentNode(ll ms=0, ll me=0, ll mcov=0):s(ms), e(me), cov(mcov), left(NULL), right(NULL) {}
};


//SegmengTree: Link
class SegmentTreeLink {
public:
    SegmentNode * T;
    void initRange(ll n1, ll n2) {
        T = new SegmentNode(n1, n2, 0);
    }
    
    void insertTreeNode(ll num) {
        insertNode(T, T->s, T->e, num);
    }
    
    SegmentNode * insertNode(SegmentNode * & T, ll n1, ll n2, ll num) {
        //cout << n1 << "\t" << n2 << "\t" << num << endl;
        if(T == NULL) {
            SegmentNode * node = new SegmentNode(n1, n2, 0);
            T = node;
            insertNode(T, n1, n2, num);
            return T;
        }
        
        if(num < n1 || num > n2)
            return NULL;
        
        (T->cov)++;

        if( n1 == n2) {
            //cout << "insert n1=n2:" << n1 << endl;
            //(T->cov)++;
            return T;
        }
        
        ll m= getMedian((T->s), (T->e));
        if(num <= m) {
            SegmentNode * node = insertNode(T->left, n1, m, num);
            if(T->left == NULL)
                T->left = node;
            return T->left;
        }
        else {
            SegmentNode * node = insertNode(T->right, m+1, n2, num);
            if(T->right == NULL)
                T->right = node;
            return T->right;
        }
    }
    
    int findTreeRange(ll nmin, ll nmax) {
        return findRange(T, nmin, nmax);
    }
    
    
    int findRange(SegmentNode *  T, ll nmin, ll nmax) {
       
        if(T == NULL) {
            return 0;
        }
        
        //cout << "findRange:" << T->s << "\t" << T->e << endl;
        
        if(nmin > nmax) {
            return 0;
        }
        
        
//        if(nmin < T->s) {
//            nmin = T->s;
//        }
//        
//        if(nmax > T->e) {
//            nmax = T->e;
//        }
        
        int res =0;
        if((T->s == nmin) && (T->e == nmax)) {
            res = (T->cov);
            //cout << "res findRange:" << nmin << "\t" << nmax << endl;
            return res;
        }
        
        ll m= getMedian((T->s), (T->e));
        //cout << "m:" << m << endl;
        if(nmax <= m) {
            res+= findRange(T->left, nmin, nmax);
        }
        else if(nmin > m) {
            res+=  findRange(T->right, nmin,nmax);
        }
        else {
            res +=  findRange(T->left, nmin, m) + findRange(T->right, m+1, nmax) ;
            
        }
        return res;
        
    }
    
    ll getMedian(ll a, ll b) {
        ll res = floor((double)(a+b)/2);
        return res;
    }
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int N = nums.size();
        vector<long long> s(N, 0);
        calVecSum(nums, s);
        int res=0;
        
//        printVecLL(s);
        
        countRangeSumSegmentTree(s, lower, upper, res);
        
        return res;
    }
    
    void calVecSum(vector<int> & nums, vector<ll> & s) {
        ll sum=0;
        for(int i=0; i < nums.size(); i++) {
            if(i == 0)
                s[i] = nums[i];
            else
                s[i] = s[i-1] + nums[i];
        }
    }

    void printVecLL(vector<ll> & s) {
        for(int i=0; i < s.size(); i++) {
            cout << s[i] << "\t";
        }
        cout << endl;
    }
    
    ll getMin(ll l1, ll l2){
        ll res = min(l1, l2);
        return res;
    }
    
    ll getMax(ll l1, ll l2){
        ll res = max(l1, l2);
        return res;
    }
    void countRangeSumSegmentTree(vector<ll>& nums, int lower, int upper, int & res) {
  
        ll nmin = getVecMin(nums);
        ll nmax = getVecMax(nums);

        SegmentTreeLink tree;
        ll rlower = lower + getMin(0, nmin);
        ll rupper = upper + getMax(0, nmax);
        
        rlower = min(nmin, rlower);
        rupper = max(nmax, rupper);
        
        tree.initRange(rlower, rupper);
        
        //        cout << "nmin, nmax:" <<  nmin << ",\t" << nmax  << endl;
        //        cout << "lower, upper:" <<lower << ",\t" << upper << endl;
        //       cout << "min, nmax:" << rlower << ",\t" << rupper << endl;
        
        int N = (int)nums.size();
        for(int i=N-1; i >= 0; i--) {
            tree.insertTreeNode(nums[i]);
            ll num = 0;
            if(i > 0)
                num = nums[i-1];
            
            ll low = num + lower;
            ll upp = num + upper;
//            cout << "low, upp:" << low << ",\t" << upp << endl;
            int count = tree.findTreeRange(low, upp);
//            cout << "i, count:" << i << "\t" << count << endl;
            res += count;
        }
    }
    
    ll getVecMin(vector<ll>& nums) {
        ll res = LONG_LONG_MAX;
        for(int i=0; i < nums.size(); i++) {
            res = min(res, nums[i]);
        }
        return res;
    }
    
    ll getVecMax(vector<ll>& nums) {
        ll res = LONG_LONG_MIN;
        for(int i=0; i < nums.size(); i++) {
            res = max(res, nums[i]);
        }
        return res;
    }
    
};

int main() {
    Solution sol;
    

    vector<int> v({0,-1,-2,-3,0,2});
    int lower=3;
    int upper=5;
 

    
    int res = sol.countRangeSum(v, lower, upper);
    cout << res << endl;
    
    
    return 0;
}

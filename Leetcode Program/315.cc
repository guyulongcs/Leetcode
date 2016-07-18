#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

#include <algorithm>

using namespace std;

//SegmengTree Node
class SegmentNode {
public:
    int s;
    int e;
    int cov;
    SegmentNode * left;
    SegmentNode * right;
    //SegmentNode():s(0), e(0), cov(0), left(NULL), right(NULL) {}
    SegmentNode(int ms=0, int me=0, int mcov=0):s(ms), e(me), cov(mcov), left(NULL), right(NULL) {}
};


//SegmengTree: Array
class SegmentTreeArray {
public:
    vector<SegmentNode> v;
    SegmentTreeArray(int nmin, int nmax) {
        int N = nmax-nmin+1;
        int Num = N * 3 + 1;
        v = vector<SegmentNode>(Num, SegmentNode());
       
    }
    
    void initSegmentTreeArray(int nmin, int nmax) {
         init(0, nmin, nmax);
    }
    
    void init(int start, int nmin, int nmax) {
        v[start] = SegmentNode(nmin, nmax);
        
        if(nmin == nmax)
            return;
        
        int m = getMedian(nmin, nmax);
        init(start*2+1, nmin, m);
        init(start*2+2, m+1, nmax);
    }
    
    void insertTreeNode(int num) {
        insertNode(0, num);
    }
    
    void insertNode(int start, int num) {
        SegmentNode node = v[start];
        v[start].cov++;
        if(node.s == node.e) {
//            if(node.s == num) {
//                v[start].cov++;
//            }
            return;
        }
        int m =getMedian(node.s, node.e);
        if(num <= m) {
            insertNode(start*2+1, num);
        }
        else {
            insertNode(start*2+2, num);
        }
    }
    
    int findTreeRange(int nmin, int nmax) {
    
        int res = findRange(0, nmin, nmax);
        return res;
    }
    
    int findRange(int start, int nmin, int nmax) {
        
        if(nmax < nmin)
            return 0;
        
        SegmentNode node = v[start];
        int m = getMedian(node.s, node.e);
        
//        cout << "findRange: start:" << start << ", nmin:" << nmin << ", nmax:" << nmax << endl;
//        cout << "start:" << start << endl;
//        cout << "s:" << node.s << ",e:" << node.e << endl;
//        cout << "m:" << m << endl;
        
        int res = 0;
        if((nmin == node.s) && (nmax == node.e)) {
            res += node.cov;
            return res;
        }
       
        if(nmax <= m) {
            res += findRange(start * 2+1, nmin, nmax);
        }
        else if(nmin > m) {
            res += findRange(start * 2 + 2, nmin, nmax);
        }
        else {
            res += findRange(start * 2+1, nmin, m) + findRange(start * 2 + 2, m+1, nmax);
        }
        
        return res;
    }

    
    
    int getMedian(int a, int b) {
        int res = floor((float)(a+b)/2);
        return res;
    }

};


//SegmengTree: Link
class SegmentTreeLink {
public:
    SegmentNode * T;
    void initRange(int n1, int n2) {
        T = new SegmentNode(n1, n2, 0);
    }
    
    void insertTreeNode(int num) {
        insertNode(T, T->s, T->e, num);
    }
    
    
    
    SegmentNode * insertNode(SegmentNode * & T, int n1, int n2, int num) {
        //        cout << "insertNode: n1:" << n1 << ", n2:" << n2 << ", num:" << num << endl;
        
        if(T == NULL) {
            //            cout << "T== NULL" << endl;
            //            cout << "n1:" << n1 << ", n2:" << n2 << endl;
            SegmentNode * node = new SegmentNode(n1, n2, 0);
            T = node;
            insertNode(T, n1, n2, num);
            return T;
        }
        
        (T->cov)++;
        if( n1 == n2) {
            //(T->cov)++;
            //            cout << "n1==n2"<<endl;
            return T;
        }
        
        int m= getMedian((T->s), (T->e));
        //        cout << "m:" << m << endl;
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
    
    int findTreeRange(int nmin, int nmax) {
        return findRange(T, nmin, nmax);
    }
    
    
    int findRange(SegmentNode *  T, int nmin, int nmax) {
        
//        cout << endl<< "findRange...nmin:" << nmin << ", nmax:" << nmax << endl;
        
        if(T == NULL) {
            return 0;
        }
        
        if(nmin > nmax) {
            return 0;
        }
        
//        
//        if(nmin == nmax) {
//            return T->cov;
//        }
        int res =0;
        if((T->s == nmin) && (T->e == nmax)) {
            res = (T->cov);
            return res;
        }
        
//                cout << "T->s:" << T->s << ", T->e" << T->e << endl;
        int m= getMedian((T->s), (T->e));
//                cout << "m:" << m << endl;
        
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
    
    int getMedian(int a, int b) {
        int res = floor((float)(a+b)/2);
        return res;
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> v;
        v = countSmallerLink(nums);
        //v = countSmallerArray(nums);
        return v;
    }
    
    //SegmentTree Array
    vector<int> countSmallerArray(vector<int>& nums) {
        vector<int> res;
        
        if(nums.size() == 0)
            return res;
        
        int nmin = getVecMin(nums);
        int nmax = getVecMax(nums);
        
        //        cout << "nmin:" << nmin << endl;
        //        cout << "nmax:" << nmax << endl;
        
        
        SegmentTreeArray tree(nmin, nmax);
        tree.initSegmentTreeArray(nmin, nmax);

        int N = nums.size();
        for(int i=N-1; i >= 0; i--) {
            int num = nums[i];
            //            cout << "num:" << num << endl;
            int count = tree.findTreeRange(nmin, num-1);
            //            cout << "count:" << count << endl;
            res.push_back(count);
            
            tree.insertTreeNode(num);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }

    //SegmentTree List
    vector<int> countSmallerLink(vector<int>& nums) {
        vector<int> res;
        
        int nmin = getVecMin(nums);
        int nmax = getVecMax(nums);
        
//        cout << "nmin:" << nmin << endl;
//        cout << "nmax:" << nmax << endl;

        
        
        SegmentTreeLink tree;
        tree.initRange(nmin, nmax);
        
        int N = nums.size();
        for(int i=N-1; i >= 0; i--) {
            int num = nums[i];
//            cout << "num:" << num << endl;
            int count = tree.findTreeRange(nmin, num-1);
//            cout << "count:" << count << endl;
            res.push_back(count);
            
            tree.insertTreeNode(num);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    int getVecMin(vector<int>& nums) {
        int res = INT32_MAX;
        for(int i=0; i < nums.size(); i++) {
            res = min(res, nums[i]);
        }
        return res;
    }
    
    int getVecMax(vector<int>& nums) {
        int res = INT32_MIN;
        for(int i=0; i < nums.size(); i++) {
            res = max(res, nums[i]);
        }
        return res;
    }
};


int main() {
    Solution s= Solution();
 
    
    vector<int> nums({5,2,6,1});
    
    vector<int> res = s.countSmaller(nums);
    
    for(int i=0; i < res.size(); i++) {
        cout << res[i] << "\t";
    }
    cout << endl;
    
    return 0;
}


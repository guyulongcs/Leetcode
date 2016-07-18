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


//SegmengTree: Link
class SegmentTreeLink {
public:
    SegmentNode * T;
    void initRange(int n1, int n2) {
        T = new SegmentNode(n1, n2, 0);
    }
    
    void insertTreeNode(int pos, int num) {
        insertNode(T, T->s, T->e, pos, num);
    }
    
    
    
    SegmentNode * insertNode(SegmentNode * & T, int n1, int n2, int pos, int num) {
        //        cout << "insertNode: n1:" << n1 << ", n2:" << n2 << ", num:" << num << endl;
        
        if(T == NULL) {
            //            cout << "T== NULL" << endl;
            //            cout << "n1:" << n1 << ", n2:" << n2 << endl;
            SegmentNode * node = new SegmentNode(n1, n2, 0);
            T = node;
            insertNode(T, n1, n2, pos, num);
            return T;
        }
        
        (T->cov) += num;
        if( n1 == n2) {
            //(T->cov)++;
            //            cout << "n1==n2"<<endl;
            return T;
        }
        
        int m= getMedian((T->s), (T->e));
        //        cout << "m:" << m << endl;
        if(pos <= m) {
            SegmentNode * node = insertNode(T->left, n1, m, pos, num);
            if(T->left == NULL)
                T->left = node;
            return T->left;
        }
        else {
            SegmentNode * node = insertNode(T->right, m+1, n2, pos, num);
            if(T->right == NULL)
                T->right = node;
            return T->right;
        }
    }
    
    void updateTreeNode(int pos, int value, int delta) {
        updateTreeNode(T, pos, value, delta);
    }
    
    void updateTreeNode(SegmentNode *  T, int pos, int value, int delta) {
        if(T == NULL) {
            return;
        }
        
        (T->cov) += delta;

        if(T->s == T->e) {
            return;
        }
        
        int m= getMedian((T->s), (T->e));
        if(pos <= m) {
            updateTreeNode(T->left, pos, value, delta);
        }
        else if(pos > m) {
            updateTreeNode(T->right, pos, value, delta);
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



class NumArray {
public:
    SegmentTreeLink T;
    vector<int> v;
    NumArray(vector<int> &nums) {
        int N = nums.size();
        v = vector<int>(nums);
        T.initRange(0, N-1);
        for(int i=0; i < N; i++) {
            T.insertTreeNode(i, v[i]);
        }
    }
    
    void update(int i, int val) {
        
        int delta = val - v[i];
        
        if(delta == 0)
            return;
        
        T.updateTreeNode(i, val, delta);
        v[i] = val;
    }
    
    int sumRange(int i, int j) {
        int res = T.findTreeRange(i, j);
        return res;
    }
    
};

int main() {
    vector<int> nums({1,3,5});
    NumArray na= NumArray(nums);
    int res=0;
    res = na.sumRange(0,2);
    cout << res << endl;
    
    na.update(1, 2);
    
    res = na.sumRange(0,2);
    cout << res << endl;
    
    return 0;
}


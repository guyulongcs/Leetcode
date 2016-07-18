#include <iostream>
//#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int res = catlan(n);
        return res;
    }
    
    int catlan(int n) {
        int * a = new int[n+1];
        a[0]=1;
        for(int i=1; i <= n;i++) {
            int sum=0;
            for(int k=1; k <=i; k++) {
                sum += a[k-1]*a[i-k];
            }
            a[i]=sum;
        }
        int res = a[n];
        delete []a;
        return res;
    }
};

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    Solution s;


    int m=3;
    int n=3;
    int aa[][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    int res = 0;
    res = s.numTrees(4);
    cout << res << endl;
    return 0;
}

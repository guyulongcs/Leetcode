#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int res=0;
        
        int k = (int)sqrt(n);
        vector<int> a(n+1, INT32_MAX);
        
        a[0] = 0;
        for(int i=1; i<=k; i++) {
            for(int j=1; j <= n; j++) {
                if(j >= i*i) {
                    a[j] = min(a[j], 1 + a[j-i*i]);
                }
            }
        }
        
        res = a[n];
        return res;
    }
};

int main() {
    int a[] = {10,9,2,5,3,7,101,18};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    
    int m=3;
    int n=3;
    int aa[][3] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    
    Solution s;
    
    
    int res = 0;
    res = s.numSquares(12);
    cout << res << endl;
    return 0;
}

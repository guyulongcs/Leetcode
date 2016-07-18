#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>


using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
  
        
        vector<int> u(n+1,1);
        
        int i2=1;
        int i3=1;
        int i5=1;
        
        int f2=2;
        int f3=3;
        int f5=5;
        
        u[1] = 1;
        for(int i=2; i <= n; i++){
            int minValue = minV(f2, f3, f5);
            u[i] = minValue;
            
            if(minValue == f2) {
                f2 = 2 * u[++i2];
            }
            if(minValue == f3) {
                f3 = 3 * u[++i3];
            }
            if(minValue == f5) {
                f5 = 5 * u[++i5];
            }
        }
        
        return u[n];
    }
    
    int minV(int v1, int v2, int v3) {
        int m=min(v1, v2);
        m = min(m, v3);
        return m;
    }
    int findMinIndex(vector<int> ndp) {
        int minIndex = 0;
        if(ndp[1] < ndp[0]) {
            minIndex = 1;
            if(ndp[2] < ndp[1])
                minIndex = 2;
        }
        else {
            if(ndp[2] < ndp[0])
                minIndex = 2;
        }
        return minIndex;
    }
    bool isUgly(int num) {
        if(num < 1)
            return false;
        if(num == 1)
            return true;
        
        vector<int> v({2, 3, 5});
        
        for(int i=0; i<v.size();i++) {
            while(num %v[i] == 0) {
                num = num / v[i];
            }
        }
        
        bool flag = false;
        if(num == 1)
            flag = true;
        
        return flag;
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
    for(int i=1; i <= 10; i++) {
        res = s.nthUglyNumber(i);
        cout << i <<":" << res << endl;
    }
    cout << res << endl;
    return 0;
}

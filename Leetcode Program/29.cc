#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;



class Solution {
public:
    int divide(int n1, int n2) {
        
        long long a = n1;
        long long b = n2;
        
        if(b == 0) {
            return INT32_MAX;
        }
        
        bool fNeg = false;
        if( (a > 0 && b < 0) || (a < 0 && b > 0)) {
            fNeg = true;
        }
        
        a = abs(a);
        b = abs(b);
        
        if(a < b)
            return 0;
        
        
        if(a == 0)
            return 0;
        
        long long res = (long long)(exp(log(a) - log(b)));
        
//        cout << "res:" << res << endl;
//        cout << "fNeg:" << fNeg << endl;
//        
        if(res > 0 && fNeg) {
            
            res = -res;
        }
        if(res > INT32_MAX)
            res = INT32_MAX;
        return res;
    }
};

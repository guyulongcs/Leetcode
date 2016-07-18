nclude <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool fNeg = false;
        if( x < 0) {
            fNeg = true;
        }
        x=abs(x);
        
        
        long long res=0;
        while(x > 0) {
            int m = x%10;
            res = res * 10 + m;
            x = x/10;
        }
        
        if(res > INT32_MAX) {
            res = 0;
        }
        
        if(fNeg)
            res = -res;
        
        return res;
    }
    
};


int main() {


    Solution s;
    cout << INT32_MAX << endl;

    int res = s.reverse(-1563847412) ;

    cout  << res << endl;


    return 0;
}


#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
        bool flag = false;
        if(x < 0 && n%2 == 1)
            flag = true;
        
        
        double res = exp(n*log(abs(x)));
        if(flag)
            res = -res;
        return res;
    }
};


int main() {
    
    
    Solution s;
    
    int a[] = {0};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    
    //cout << v[0] << endl;
    
    int res=0;
    
    

    
    int i = 0;
    
    
    double res2 = s.myPow(0,  13);

    cout << res2 << endl;
    
    cout << endl;

    
    return 0;
}


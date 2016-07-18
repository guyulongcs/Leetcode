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
    int mySqrt(int x) {
        int res=0;
        if(x <= 0)
            return 0;
        
        if( x == 1)
            return 1;
        
        //x = x/2;
        
        int l = 0;
        int r=x;
        while(l <= r) {
            int m = (l+r)/2;
            
            if(m < x/m)
                l = m + 1;
            
            else if(m > x/m)
                r=m-1;
            else {
                res = m;
                break;
            }
        }
        if(l > r)
            res = r;
        
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
    int n=2147395599;
    
    int mi=0;
    int ma=100;
    
//    for(int i=mi; i <= ma; i++) {
//        int res2 = s.mySqrt(i);
//
//        cout << i << "\t" << res2 << endl;
//    }
    cout << n << "\t" << s.mySqrt(n) << endl;
    
    cout << endl;

    
    return 0;
}


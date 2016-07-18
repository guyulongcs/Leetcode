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
    int trailingZeroes(int n) {
        if(n <= 0)
            return 0;
        
        int res = 0;
        
        while(n) {
            res += n/5;
            n = n/5;
        }
        return res;
    }
};

int main() {
    
    
    Solution s;
    
    int a[] = {0};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    
    //cout << v[0] << endl;
    
    int res=0;
    
    

    for(int i=0; i <= 100; i++) {
        res = s.trailingZeroes(i);
        cout << i <<"," << res << endl;
    }
    cout << endl;

    
    return 0;
}


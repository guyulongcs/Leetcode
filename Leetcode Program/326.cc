#include<iostream>
#include<cmath>
using namespace std;



class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        int maxPow = pow(3, (int)(log(INT_MAX)/log(3)));
        bool res = (maxPow % n == 0);
        return res;
    }
};

int main() {
    Solution s = Solution();
    int res = 0;
    
    for(int i=0; i < 300; i++) {
        res = s.isPowerOfThree(i);
        cout << i << " " << res << endl;
    }
    return 0;
}


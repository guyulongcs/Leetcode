#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0)
            return false;
        if(num == 0)
            return true;
        
        bool flag = false;
        int left = 1;
        int right = num;
        while(left <= right) {
            long long tmp = (long long)left + right;
            long long mid = tmp / 2;
            long long square = mid * mid;
            if(square == num) {
                flag = true;
                break;
            }
            else if(square < num){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return flag;
        
    }
};

int main() {


    Solution s;
    
    int n = 2147483647;
    bool res = s.isPerfectSquare(n);
    cout << n << "\t" << res << endl;
    
    
    return 0;
}


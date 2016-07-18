#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;


class Solution {
public:
    
    int getSum(int a, int b) {
        int sum=a;
        int carry = b;
        while(carry != 0) {
            int res = sum ^ carry;
            carry = (sum & carry) << 1;
            sum = res;
        }
        return sum;
    }
};


int main() {
    Solution s;
    
    int a=1;
    int b=2;
    int res = s.getSum(a, b);
    cout << res << endl;
    return 0;
}


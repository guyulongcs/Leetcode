#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isPowerOfFour(int num) {
        
        if((num & (num-1)) != 0)
            return false;

//        if((num-1) % 3 != 0)
//            return false;

        if((num & 0x55555555) == 0)
            return false;
        return true;
    }
};



int main() {
    Solution s= Solution();
    bool res = s.isPowerOfFour(16);
    cout << res << endl;
    return 0;
}



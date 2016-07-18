nclude <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low=1;
        int high=n;
        int res;
        
        while(low <= high) {
            int cur = low + (high-low)/2;
//            cout << "cur:" << cur << endl;
            int feedback=guess(cur);
            if(feedback == 0) {
                return cur;
            }
            else if(feedback==1) {
                low = cur+1;
            }
            else {
                high = cur-1;
            }
        }
        return res;
    }
};

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
    int ans = 6;
    if(num == ans) {
        return 0;
    }
    else if(num > ans) {
        return -1;
    }
    else {
        return 1;
    }
}


int main() {
    Solution sol = Solution();

    int n=10;
    int res=sol.guessNumber(6);
    cout << res << endl;



    return 0;
}



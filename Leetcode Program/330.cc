#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long dp = 0;
        long long curMax= 0;
        int addCnt=0;
        int pos = 0;
        
        while(dp < n) {
            if(pos < nums.size() && nums[pos] <= dp+1) {
//                if(nums[pos] > curMax) {
//                    curMax = nums[pos];
//                }
                dp = dp + nums[pos];
                pos++;
            }
            else {
                addCnt++;
                curMax = dp + 1;
                dp = dp + curMax;
            }
            
        }
    
        return addCnt;
    }
    
    
};

int main() {


    Solution s;
    vector<int> v({1,2,31,33});
    int n=2147483647;

    int res = s.minPatches(v, n);
    cout << res << endl;

    return 0;
}



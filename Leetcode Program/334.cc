#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();
        if(N < 3)
            return false;
        int a=INT32_MAX;
        int b=INT32_MAX;
        bool flag = false;
        for(int i=0; i < nums.size(); i++) {
            int num = nums[i];
            if(num <= a) {
                a = num;
            }
            else if(num <= b) {
                b = num;
            }
            else {
                flag = true;
                break;
                
            }
        }
        return flag;
    }
};

int main() {
    
    vector<int> v({2,4,2,-3});
    
    Solution s;
    bool res = s.increasingTriplet(v);
    
    cout << res << endl;
    
    return 0;
}


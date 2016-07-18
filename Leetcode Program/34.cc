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
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> resNeg = vector<int>({-1, -1});
        if(N == 0 || nums[0] > target || nums[N-1] < target) {
            return resNeg;
        }
        
        vector<int> res;
        
        int l =0;
        int r = N-1;
        
        bool flag = false;
        
        
        //left
        int left = 0;
        l = 0;
        r=N-1;
        while(l <= r) {
            if(nums[l] == target)
                break;
            int m = (l+r) / 2;
            if(nums[m] < target) {
                 l = m+1;
            }
            else if(nums[m] == target) {
                l++;
            }
            else {
                r=m-1;
            }
        }
        if(l > r) {
            left = -1;
        }
        else {
            left = l;
        }
        
        //right
        //left
        int right = 0;
        l = 0;
        r=N-1;
        while(l <= r) {
            if(nums[r] == target)
                break;
            int m = (l+r) / 2;
            if(nums[m] < target) {
                l = m+1;
            }
            else if(nums[m] == target) {
                r--;
            }
            else {
                r=m-1;
            }
        }
        if(l > r) {
            right = -1;
        }
        else {
            right = r;
        }

        res.push_back(left);
        res.push_back(right);
        return res;
    }
    
    
};


int main() {

    Solution s;
  
    vector<int> v({5,8});

    vector<int> res = s.searchRange(v, 8);
    cout << res[0] << "\t" << res[1] << endl;

    return 0;
}


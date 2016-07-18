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
    int findPeakElement(vector<int>& nums) {
        int res = 0;
        int N = nums.size();
        for(int i=0; i < N; i++) {
            if(isPeak(nums, N, i)) {
                res = i;
                break;
            }
        }
        return res;
    }
    
    bool isPeak(vector<int>& nums, int N, int p) {
        bool flag = false;
        if(p==0) {
            if(nums[p] > nums[p+1]) {
                flag = true;
            }
        }
        else if(p == N-1) {
            if(nums[p] > nums[p-1]) {
                flag = true;
            }
        }
        else {
            if((nums[p] > nums[p-1]) && (nums[p] > nums[p+1])) {
                flag = true;
            }
        }
        return flag;
    }
    
};


int main() {

    Solution s;
  
    vector<int> v({1,2,3,1});

    int res = s.findPeakElement(v);
    cout << res << endl;

    return 0;
}


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int n = len-1;
        int low = 1;
        int high = n;
        int mid = 0;
        
        while(low < high) {
            mid = (low + high) / 2;
            int cnt = countArrNum(nums, mid);
            if(cnt > mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int countArrNum(vector<int>& nums, int n) {
        int res = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] <= n)
                res ++;
        }
        
        return res;
    }
};

int main() {
    Solution s = Solution();
    int a[] = {2,2,2};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    int res = s.findDuplicate(v);
    cout << res << endl;
}


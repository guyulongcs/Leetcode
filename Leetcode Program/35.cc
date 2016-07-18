#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < target){
                res = i+1;
            }
            else if(nums[i] == target) {
                res = i;
                break;
            }
            else
                break;
            
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    int res = 0;
    int a[] = {1,3,5,6};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    res = s.searchInsert(v, 0);
    cout << res << endl;
}


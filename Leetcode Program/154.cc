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
    int findMin(vector<int>& nums) {
        int N = nums.size();
        
        int res=0;
        
        int b = 0;
        int e = N-1;
        while(true) {
            int m = (b+e)/2;
            if(nums[m] > nums[e]) {
                b=m+1;
            }
            else if(nums[m] < nums[e]) {
                e=m;
            }
            else {
                if(nums[b] < nums[m]) {
                    e=m-1;
                }
                else if(nums[b] >= nums[m]) {
                    b = b+1;
                }
            }
            if(b >= e)
                break;
        }
        res = nums[e];
        return res;
    }
};


int main() {

    Solution s;

    vector<int> v({3,4,5,6,7,8,0,1,2});
    int res = s.findMin(v);

    cout << res << endl;

    return 0;
}


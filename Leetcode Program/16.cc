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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        if( N < 3)
            return 0;
        
        
        int minDiff = INT32_MAX;
        int i=0;
        int res = 0;
        for(i=0; i <= N-3; i++){
            int resTwo = twoSumCloset(nums, i+1, N-1, target-nums[i]);
            int cur = resTwo + nums[i];
            int diff = abs(cur - target);
            if(diff < minDiff) {
                minDiff = diff;
                res = cur;
//                cout << "res:" << res << "\t" << minDiff << endl;
            }
            //cout << nums[i] << "\t" << cur << "\t" << diff << endl;
        }
//        cout << "res:" << res << "\t" << minDiff << endl;

        
        return res;
    }
    
    int twoSumCloset(vector<int>& nums, int s, int e, int target) {
        int i=s;
        int j=e;
        int minDiff = INT32_MAX;

        int res= 0;
        while(i < j) {
            int cur = nums[i] + nums[j];
            int diff = abs(cur - target);
            if(diff < minDiff) {
                minDiff = diff;
                res = cur;
            }
            if(cur == target) {
                break;
            }
            else if(cur < target){
                i++;
            }
            else {
                j--;
            }
        }
        return res;
    }
    
    
};

int main() {


    Solution s;
    vector<int> v({-1,2,1,-4});
    int n=1;

    int res = s.threeSumClosest(v, n);
    cout << res << endl;

    return 0;
}



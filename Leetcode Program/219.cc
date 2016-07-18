#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int N = nums.size();
        
        if(k < 0)
            k=0;
        
        unordered_map<int, vector<int> > map;
        bool flag = false;
        for(int i=0; i < N; i++) {
            int num = nums[i];
            if(map.find(num) == map.end()) {
                map[num] = vector<int>(2, 0);
                map[num][0] = i;
                map[num][1] = INT32_MAX;
            }
            else {
                int diff = i-map[num][0];
                map[num][0] = i;
                diff = min(map[num][1], diff);
                if(diff <= k) {
                    flag = true;
                    break;
                }
                map[num][1] = diff;
            }
        }
        
        return flag;
    }
    bool containsNearbyDuplicate0(vector<int>& nums, int k) {
        int N = nums.size();
        if(k < 0)
            k=0;
        bool flag = false;
        for(int i=0; !flag && i < N; i++) {
            for(int j=i+1; j <= i+k && j < N; j++) {
                if(nums[i] == nums[j]) {
                    flag = true;
                    break;
                }
                    
            }
        }
        return flag;
    }
    
};


int main() {
    

    Solution s;
    vector<int> v1({1,0,1,1});
    vector<int> v2({});
    bool flag = s.containsNearbyDuplicate(v1, 1);

    cout << flag << endl;
    
    
    return 0;
}


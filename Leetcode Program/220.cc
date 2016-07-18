#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        bool flag = false;
        multiset<long long> bst;
        int N = (int)nums.size();
        for(int i=0; i < N; i++) {
            if(bst.size() > k) {
                bst.erase(bst.find(nums[i-k-1]));
            }
            auto it = bst.lower_bound(nums[i]-t);
            if(it != bst.end() && *it-nums[i] <= t) {
                return true;
            }
            bst.insert(nums[i]);
        }
        return flag;
    }
};

int main() {
    Solution sol;
    
    vector<int> v;
    int k;
    int t;
    bool res;
    
    v = vector<int>({-1, 2147483647});
    k = 1;
    t=2147483647;
    
    
    
    res = sol.containsNearbyAlmostDuplicate(v, k, t);
    cout << res << endl;
    
    return 0;
}


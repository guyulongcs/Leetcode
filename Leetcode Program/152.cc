#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return 0;

        int lg = nums[0];
        

        int ll = nums[0];
        int sl = nums[0];

        for(int j=1; j < N; j++) {
            int tmp = ll;
            ll = max(max(ll * nums[j], nums[j]), sl * nums[j]);
            lg = max(lg, ll);
            sl = min(min(tmp * nums[j], nums[j]), sl * nums[j]);
        }
        return lg;
    }
};


int main() {


    Solution s;

    vector<int> v({-2,3,-4});
    int res = s.maxProduct(v);
    cout << res << endl;
    return 0;
}


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = 0;
        
        int N = coins.size();
        
        if(amount == 0)
            return 0;
        if(N == 0)
            return -1;
        
        int * dp = new int[amount+1];
        
        dp[0] = 0;
        for(int j=1; j <= amount; j++) {
            dp[j] = INT32_MAX;
            for(int i=0; i < N; i++) {
                if(j >= coins[i]) {
                    int tmp = dp[j-coins[i]];
                    if(tmp >= 0) {
                        dp[j] = min(dp[j], 1+dp[j-coins[i]]);
                    }
                }
            }
            if(dp[j] == INT32_MAX)
                dp[j] = -1;
        }
        res = dp[amount];
        
        
        delete []dp;
        
        return res;
    }
    
};

int main() {
    Solution s = Solution();
    int a[] = {1};
    vector<int> p(a, a + sizeof(a) / sizeof(int));
    int res = s.coinChange(p, 1);
    cout << res << endl;
    return 0;
}

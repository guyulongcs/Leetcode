#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cstdlib>
#include <cmath>
using namespace std;



class Solution {
public:
    
    int getMoneyAmount(int n) {
        if(n <= 1) {
            return 0;
        }
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT32_MAX));
        
        for(int k=0; k <= n; k++) {
            for(int i=1; i <= n && i+k <= n;  i++) {
                int j = i+k;
                if(i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                for(int c=i; c <= j; c++) {
                    int cur = c;
                    int maxNum=0;
                    if(c-1 >= i) {
                        maxNum = max(maxNum, dp[i][c-1]);
                    }
                    if(c+1 <= j)
                    {
                        maxNum = max(maxNum, dp[c+1][j]);
                    }
                    cur += maxNum;
                    dp[i][j] = min(dp[i][j], cur);
                }
            }
        }
        
        int res = dp[1][n];
        return res;
    }
};

int main(int argc, char * argv[]) {

    int n;
    Solution sol;
    
    int res;
    
    n=10;
    res = sol.getMoneyAmount(n);
    cout << res << endl;
    
    
    return 0;
    
}

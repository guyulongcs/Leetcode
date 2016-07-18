#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return true;
        
        bool res = false;
        res = solveDp2(nums, N);
        //res = solveDfs(nums, N);
        
        return res;
    }
    
    bool solveDfs(vector<int>& nums, int N) {
        bool flag = false;
        
        vector<int> dp(N, -1);
        dp[N-1]=1;
        
        flag = dfs(nums, N, 0, dp);
        
        return flag;
        
    }
    
    bool dfs(vector<int>& nums, int N, int b, vector<int>& dp) {
        if(dp[b] != -1) {
            return (dp[b] == 1);
        }
        bool flag = (nums[b] > (N-1-b));
        int kmax = min(nums[b], N-1-b);
        for(int k=kmax; !flag && k >= 1; k--) {
            flag = dfs(nums, N, b+k, dp);
        }
        dp[b] = flag;
        return flag;
    }
    
    bool solveDp(vector<int>& nums, int N) {
        vector< bool> dp(N,false);
        dp[N-1] = true;
        for(int j=N-2; j >= 0; j--) {
            bool flag = (nums[j] >= (N-1-j));
            if(!flag)
            {
                for(int k=min(j+nums[j], N-1); k >= j+1; k--) {
                    if(dp[k]) {
                        flag = true;
                        break;
                    }
                }
            }
            dp[j] = flag;
        }
        
        bool res = dp[0];
        return res;
    }
    
    bool solveDp2(vector<int>& nums, int N) {
        if(N==1)
            return true;
        //read max
        vector< int> dp(N,0);

        dp[0]=nums[0];
        bool flag = false;
        for(int j=0; j <= N-1; j++) {
            if(j >= 1)
                dp[j] = max(nums[j], dp[j-1]-1);
            if(j + dp[j] >= N-1) {
                flag = true;
                break;
            }
            if(dp[j] == 0) {
                break;
            }
        }
    
        return flag;
    }

    
};


int main() {

    Solution s;
    vector<int> v({0,1});
    bool res = s.canJump(v);
    cout << res << endl;
    return 0;
}

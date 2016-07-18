#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        if(N <= 1)
            return 0;
        
        int res = INT32_MAX;
        
        res = jumpGreedy(nums, N);
        
        int step=0;
        
        vector<int> dp(N, -1);
        int minStep = INT32_MAX;
        //res = dfs(nums, 0, N-1, dp, minStep);
        return res;
    }
    
    int jumpGreedy(vector<int>& nums, int N) {
        int jumpCnt=0;
        int curJmpReach = 0;
        int curMax=0;
        
        for(int i=0; i < N; i++) {
            if(curJmpReach < i) {
                jumpCnt++;
                curJmpReach = curMax;
            }
            curMax = max(curMax, nums[i]+i);
        }
        
        return jumpCnt;
        
    }
    int jumpDp(vector<int>& nums, int N) {
        //read max
        vector< long long> dp(N,0);
        
        dp[N-1]=0;
        
        //        cout << N << endl;
        for(int j=N-2; j >=0 ; j--) {
            dp[j] = INT32_MAX;
            if(nums[j] >= N-1-j)
                dp[j] = 1;
            for(int k=j+1; k <= j + nums[j]; k++) {
                dp[j] = min(dp[j], 1+dp[k]);
            }
            //                        cout << "j:" << j << ",dp[j]:" << dp[j] << endl;
        }
        int res = dp[0];
        
        return res;
    }
    
    int jumpDp2(vector<int>& A, int n) {
        if(n <= 1) return 0;
        int *dp = new int[n + 1];
        for(int i=1;i<n;i++)
            dp[i] = INT_MAX;
        
        dp[0] = 0;
        for(int i = 1; i < n;i++)
        {
            for(int j = 0;j < i;j++)
                if(A[j] + j >= i)
                {
                    if(dp[j] + 1 < dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        break;
                    }
                }
        }
        
        return dp[n - 1];
    }
    
    int dfs(vector<int>& nums, int s, int e, vector<int> & dp, int & minStep) {
        if(s >= e) {
            return 0;
        }
        
        if(dp[s] >= 0) {
            return dp[s];
        }
        
        
        long long minStepCur = INT32_MAX;
        for(int i=nums[s]; i >= 1; i--) {
            long long cur = 1 + (long long)dfs(nums, s+i, e, dp, minStep);
            minStepCur = min(minStepCur, cur);
        }
        
        dp[s] = minStepCur;
        minStep= min(minStep, dp[s]);
        //cout << s << "\t" << minStep << endl;
        return dp[s];
    }
};

int main() {
    
    Solution s;
    vector<int> v({2,3,1,1,4});
    int res = s.jump(v);
    cout << res << endl;
    return 0;
    
}

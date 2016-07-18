#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& inums) {
        int N = inums.size();
        if(N == 0)
            return 0;
        
        
        int * nums = new int[N+2];
        for(int i=0;i<N;i++) {
            nums[i+1] = inums[i];
        }
        nums[0] = nums[N+1] = 1;
        

        
        int ** dp=new int *[N+2];
        for(int i=0; i < N+2;i ++) {
            dp[i] = new int[N+2];
            for(int j=0; j < N+2;j++)
                dp[i][j] = 0;
            //dp[i][i] = nums[i];
        }
        
        for(int len=1; len <= N; len++) {
            for(int left=1; left<=N-len+1; left++) {
                int right= left+len-1;
                
                for(int k=left; k<=right; k++) {
                    //int maxNum = dp[i][j];
                    int n1=dp[left][k-1];
                    int n2=dp[k+1][right];
                    int n3=nums[left-1] * nums[k] * nums[right+1];
                    int sum = n1 + n2 + n3;
                    //cout << sum << endl;
                    dp[left][right]= max(dp[left][right], sum);
                }
                //cout << i << "," << j << endl;
               
            }
        }
        
        int res = dp[1][N];
        return res;
    }
};

int main() {
    int a[] = {3,1,5,8};
    vector<int> v(a, a+4);
    
    Solution s;
    
    
    int res = 0;
    res = s.maxCoins(v);
    cout << res << endl;
    return 0;
}

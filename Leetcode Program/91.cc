#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int N = s.length();
        int res=0;
        
        if(N == 0)
            return 0;
        
        vector<int> dp(N+2, 1);
        for(int index=N-1; index >= 0; index--) {
            char ch = s[index];
            int cnt1 = 0;
            int cnt2 = 0;
            if(ch >= '1' && ch <= '9') {
                cnt1 = dp[index+1];
            }
            
            if(index+1 <= N-1) {
                string str2 = s.substr(index,2);
                if(str2 >="10" && str2 <= "26") {
                    cnt2 = dp[index+2];
                }
            }
            int cnt = cnt1 + cnt2;
            dp[index] = cnt;
        }
        
        res = dp[0];
        
        return res;
    }
};



int main() {
    Solution sol = Solution();
    
    string str="0";
    int res = sol.numDecodings(str);
    
    cout << res << endl;
   
    
    return 0;
}



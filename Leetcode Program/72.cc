#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>


using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return minDistance(s2, s1);
        }
        int dis=0;
        
        dis = minDistance_dp(s1, s2);
        return dis;
    }
    
    int minDistance_dp(string s1, string s2) {
        
        int res  = 0;
        
        int m = s1.length();
        int n = s2.length();
        if(m == 0 || n == 0)
            return max(m, n);
        
        vector< vector<int> > dp(m+1, vector<int>(n+1, 0));
        
        for(int j=n-1; j >= 0; j--) {
            dp[m][j] = n-j;
        }
        
        for(int i=m; i >= 0; i--) {
            dp[i][n] = m-i;
        }
        
        for(int i=m-1; i >=0; i--) {
            for(int j=n-1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                }
               
            }
        }
        
        return dp[0][0];
    }

    int minDistance_r(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return minDistance_r(s2, s1);
        }
        
        int l1=s1.length();
        int l2=s2.length();
        
        int dis=0;
        if(l1 == 0 || l2 == 0)
            return max(l1, l2);
        
        string s1sub = s1.substr(1);
        string s2sub = s2.substr(1);
        if(s1[0] == s2[0]) {
            return minDistance_r(s1sub, s2sub);
        }
        int d1 = 1 + minDistance_r(s1, s2sub);
        int d2 = 1 + minDistance_r(s1sub, s2sub);
        
        dis = min(d1, d2);
        
        
        return dis;
    }
};

int main() {
    
    Solution s;
    string w1="sea";
    string w2="ate";
    
    int res = s.minDistance(w1,w2);
    cout << res << endl;
    return 0;
}

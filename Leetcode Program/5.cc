#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    
    string longestPalindrome(string & s) {
        int N = s.length();
        
        int dp[1000][1000];
        for(int i=0; i < N ; i++) {
            for(int j=0; j < N; j++) {
                dp[i][j] = true;
            }
        }
        
//        vector<vector<bool>> dp(N, vector<bool>(N, true));
        
        int maxLen = 1;
        int maxi=0;
        for(int k=2; k <= N; k++) {
            for(int i=N-k; i>=0; i--) {
                int j= i+k-1;
                bool flag = false;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    flag = true;
                }
                dp[i][j] = flag;
                if(flag) {
                    if(k > maxLen) {
                        maxLen = k;
                        maxi = i;
                    }
                }
            }
        }
        
        string res = s.substr(maxi, maxLen);
        return res;
        
    }
    
    void printVecStr(vector<string> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
};


int main() {
    Solution s= Solution();

    string num = "bb";
   
    string res = s.longestPalindrome(num);
    cout << res << endl;
   
    
    return 0;
}



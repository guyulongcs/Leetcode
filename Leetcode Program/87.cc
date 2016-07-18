#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        if(l1 != l2) {
            return false;
        }
        
        int l = l1;
        
        int N = l;
        vector<vector<vector<bool>>> dp = vector<vector<vector<bool>>>(N+1, vector<vector<bool>>(N+1, vector<bool>(N+1, false)));
        for(int k=1; k <= l; k++) {
            for(int i=0; (i < l) && (i+k-1 < l); i++) {
                for(int j=0; (j < l) && (j+k-1 < l); j++) {
                    bool flag = false;
                    //sub str equal
                    if(s1.substr(i, k) == s2.substr(j, k)) {
                        flag = true;
                    }
                    
                    //l1~l2, r1 ~ r2
                    for(int m=1; !flag && m < k; m++) {
                        if(dp[i][j][m] && dp[i+m][j+m][k-m]) {
                            flag = true;
                            break;
                        }
                    }
                    
                    //l1~r2, l2~r1
                    for(int m=1; !flag && m < k; m++) {
                        if(dp[i][j+k-m][m] && dp[i+m][j][k-m]) {
                            flag = true;
                            break;
                        }
                    }
                    
                    dp[i][j][k] = flag;
                    
                }
            }
        }
        
        bool res = dp[0][0][l];
        return res;
    }
};



int main() {
    Solution s= Solution();
   
    string str1 = "great";
    string str2 =  "rgeat";
    bool flag = s.isScramble(str1, str2);
    cout << flag << endl;
    
    return 0;
}



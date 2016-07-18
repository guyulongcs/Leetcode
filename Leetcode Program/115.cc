#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        
        vector< vector<int> > dp = vector< vector<int> > (ls+1, vector<int>(lt+1, 0));
        
        dp[0][0] = 1;
        for(int i=1; i <= ls; i++) {
            dp[i][0]=1;
            for(int j=1; j <= lt; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int res = dp[ls][lt];
        return res;
        
    }
};

int main() {

    Solution sol;
    
    string s= "rabbbit";
    string t= "rabbit";
    int res = sol.numDistinct(s,t);

    cout << res << endl;



    return 0;
}


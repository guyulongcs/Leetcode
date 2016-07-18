#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int maxLen = getWordMaxLen(wordDict);
        bool flag = false;
        
        int N = s.length();
        if(N < 0)
            return false;
        vector<bool> dp(N+1, false);
        dp[N] = true;
        for(int b=N-1; b >= 0; b--) {
            bool flagCur = false;
            for(int k =b; k <= min(N+b-1, N-1); k++) {
                 string word = s.substr(b, k-b+1);
                if(wordDict.find(word) != wordDict.end() && dp[k+1]) {
                    flagCur = true;
                    break;
                }
            }
            dp[b] = flagCur;
           
        }
        flag = dp[0];
        return flag;
    }
    
    int getWordMaxLen(unordered_set<string>& wordDict) {
        int maxLen = 0;
        for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
            string str = *it;
            int len = str.length();
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

int main() {

    
    Solution s;
    string str="a";
    unordered_set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("a");
    wordDict.insert("code");
    
    bool flag = s.wordBreak(str, wordDict);
    cout << flag << endl;
    
    return 0;
}

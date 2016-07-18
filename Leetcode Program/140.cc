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
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        int N = s.length();
        if(N <= 0)
            return res;
        
        int maxLen = getWordMaxLen(wordDict);
        vector<bool> dp;
        getDp(s, N, maxLen, wordDict, dp);
        
//       printDp(N, dp);
        string cur;
        dfs(s, N, maxLen, wordDict, dp, res, 0, cur);
        return res;
    }
    
    void printDp(int N, vector<bool> & dp) {
        for(int i=0; i < N; i++) {
            cout << dp[i] << "\t";
        }
        cout << endl;
    }
  
    
    void getDp(string & s, int N, int maxLen, unordered_set<string>& wordDict, vector<bool> & dp) {
        dp = vector<bool>(N+1, false);
        dp[N] = true;
        for(int i=N-1; i >= 0; i--) {
            bool flag = false;
            for(int l=1; l <= maxLen && i+l-1 < N; l++) {
                string str = s.substr(i, l);
                if(wordDict.count(str) > 0 && dp[i+l]) {
                    flag = true;
                    break;
                }
            }
            dp[i] = flag;
        }
    }
    
    void dfs(string & s, int N, int maxLen, unordered_set<string>& wordDict, vector<bool> & dp, vector<string> & res, int i, string cur) {
        if(i >= N) {
            res.push_back(cur);
            return;
        }
        
        for(int l=1; l <= maxLen && i+l-1 < N; l++) {
            string str = s.substr(i, l);

            if((wordDict.count(str) > 0) && dp[i+l]) {
                string tmp = cur;
                if(i > 0) {
                    cur += " ";
                }
                cur += str;
                dfs(s, N, maxLen, wordDict, dp, res, i+l, cur);
                cur = tmp;
            }
        }
    }
    
    
    int getWordMaxLen(unordered_set<string>& wordDict) {
        int maxLen = 0;
        for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
            string str = *it;
            int len = (int)str.length();
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

int main() {


    Solution s;
    string str;
    unordered_set<string> wordDict;
    
    str="catsanddog";
    wordDict = {"cat", "cats", "and", "sand", "dog"};

//    str="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//    wordDict= {"a", "aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    vector<string> res = s.wordBreak(str, wordDict);
    for(int i=0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}

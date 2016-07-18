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
    string shortestPalindrome(string s) {
        int N = (int)s.length();
//        cout << "N:" << N << endl;
        if(N == 0)
            return s;
        
        int maxLen = getMaxPalinPrefixLen(s, N);
        string res = getPlainStr(s, N, maxLen);
        return res;
    }
    
    int getMaxPalinPrefixLen(string & s, int N) {
        int len =0;
        //len = getMaxPalinLenDp(s, N);
        len = getMaxPalinPrefixLenKMP(s);
        return len;
    }

    int getMaxPalinPrefixLenKMP(string & s) {
        int len = 0;
        
        string str = s + "#" + getStrReverse(s) + "#";
//        cout << "str:" << str << endl;
        int N = (int)str.length();
        vector<int> next = getNext(str, N);
        len = next[N-1];
//        cout << "len:" << len << endl;
        return len;
    }
    
    vector<int> getNext(string & s, int N) {
        vector<int> next(N, 0);
        next[0]=-1;
        int k=-1;
        int j=0;
        while(j < N-1) {
            if(k == -1 || s[k] == s[j]) {
                ++j;
                ++k;
                next[j]=k;
            }
            else {
                k=next[k];
            }
        }
        return next;
    }
    
    
    
    string getStrReverse(string & s) {
        string res = s;
        reverse(res.begin(), res.end());
        return res;
    }
    int getMaxPalinPrefixLenDp(string & s, int N) {
        //cal dp
        vector<vector<bool>> dp;
        dp = vector<vector<bool>>(N, vector<bool>(N, false));
        for(int l=1; l <= N; l++) {
            for(int i=0; i < N; i++) {
                int j=i+l-1;
                if(j >= N) {
                    continue;
                }
                bool flag = false;
                if(s[i] == s[j]) {
                    flag = true;
                    if(l >= 4 && !dp[i+1][j-1]) {
                        flag = false;
                    }
                }
                dp[i][j] = flag;
            }
        }
        
        //cal max len
        int len = 1;
        for(int l=N; l >= 1; l--)
        {
            int j= l-1;
            if(dp[0][j]) {
                len = l;
                break;
            }
        }
        return len;
    }

    
    string getPlainStr(string & s, int N, int maxLen) {
        string sub=s.substr(maxLen);
        string res = getStrReverse(sub) + s;
        return res;
    }
};

int main() {


    Solution s;
    string str;
    string res;
    
    str = "aacecaaa";
    res = s.shortestPalindrome(str);
    cout << res << endl;
    
    str = "abcd";
    res = s.shortestPalindrome(str);
    cout << res << endl;
    
    str = "a";
    res = s.shortestPalindrome(str);
    cout << res << endl;
    
    
    
    return 0;
}

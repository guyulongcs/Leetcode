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
    int minCut(string s) {
        int res=INT32_MAX;
        if(s.length() <= 1)
            return 0;
        
        int N = s.length();
        vector<string> v;
        
        vector< vector<bool> > dpPalin(N, vector<bool>(N, false));
        vector< int > dpCnt(N, -1);
        
        
        int cnt=0;
        initDp(s, N, dpPalin);
        //res = dfs_cut(0, N-1, dp, dpCnt);
        res = dp_cut(N, dpPalin);
        return res;

    }
    
    int dp_cut(int N, vector< vector<bool> > & dpPalin) {
        vector<int> dpCnt(N+1, 0);
        
        for(int i=N-1; i >= 0; i--) {
            int minCnt = INT32_MAX;
            for(int j=N-1; j>=i; j--) {
                if(dpPalin[i][j]) {
                    int cnt = dpCnt[j+1];
                    if(j != N-1) {
                        cnt++;
                    }
                    minCnt = min(minCnt,  cnt);
                }
                
            }
            dpCnt[i] = minCnt;
        }
        
        int res = dpCnt[0];
        return res;
    }
    
    void initDp(string s, int N, vector< vector<bool> > & dp) {
        for(int i=N-1; i >= 0; i--) {
            for(int j=i; j < N; j++) {
                bool flag = true;
                if(j > i) {
                    flag = (s[i] == s[j]);
                    if(i+1 < j-1) {
                        flag = flag && (dp[i+1][j-1]);
                    }
                }
                //cout << cur << "\t" << flag << endl;
                dp[i][j] = flag;
            }
        }
    }

    
    int dfs_cut(int s, int e, vector< vector<bool> > & dp, vector<int> & dpCnt) {
        //cout << "s, e:" << s << "\t" << e << endl;
        if(s > e) {
            return 0;
        }
        
        if(dpCnt[s] != -1) {
            return dpCnt[s];
        }
        
        int minCntCur = INT32_MAX;
        for(int index = e; index >= s; index--) {
            
            if(dp[s][index]) {
                int cnt = dfs_cut(index+1, e, dp, dpCnt);
                if(index != e) {
                    cnt++;
                }
                minCntCur = min(minCntCur, cnt);
            }
        }
        dpCnt[s] = minCntCur;
        
        return dpCnt[s];
        
        
    }
};



int main() {
    Solution s= Solution();

    
    string str= "ab";
    int res = s.minCut(str);
    cout << res << endl;
    return 0;
}



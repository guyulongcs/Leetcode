#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vv;
        if(s.length() == 0)
            return vv;
        
        int N = s.length();
        vector<string> v;
        
        vector< vector<bool> > dp(N, vector<bool>(N, false));
        
        initDp(s, N, dp);
        dfs(s, 0, N-1, dp, v, vv);
        

        return vv;
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
    
    void dfs(string & str, int s, int e, vector< vector<bool> > & dp, vector<string> & v, vector<vector<string>> & vv) {
        //cout << "s, e:" << s << "\t" << e << endl;
        if(s > e) {
            vv.push_back(v);
            return;
        }
        
        for(int index = s; index <= e; index++) {
            if(dp[s][index]) {
                string cur = str.substr(s, index-s+1);
                v.push_back(cur);
                dfs(str, index+1, e, dp, v, vv);
                v.pop_back();
            }
        }
        
    }
};

void printVector(vector<string> v) {
    for(int i=0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
}

void printVV(vector<vector<string>> & vv) {
    for(int i=0; i < vv.size(); i++) {
        printVector(vv[i]);
    }
}

int main() {
    Solution s= Solution();

    
    string str= "abba";
    vector<vector<string>> vv = s.partition(str);
    printVV(vv);
    return 0;
}



#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& vv) {
        int res=INT32_MAX;
        if(vv.size() == 0 || vv[0].size() == 0)
            return res;
        int M = vv.size();
        int N = vv[0].size();
        
        res = getMin(vv, M, N);
        
        return res;
    }

    int getMin(vector<vector<int>>& vv, int M, int N) {
        int res=0;
        //res=getMinDfs(vv, M, N);
        res = getMinDp(vv, M, N);
        return res;
    }
    
    int getMinDp(vector<vector<int>>& vv, int M, int N) {
        int res=0;
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for(int r=M-1; r >= 0; r--){
            for(int c=N-1; c >= 0; c--) {
                
                int cell = vv[r][c];
                int cellNew = cell;
                if(r < M-1 || c < N-1) {
                    int next=INT32_MAX;
                    if(r < M-1) {
                        next = min(next, dp[r+1][c]);
                    }
                    if(c < N-1) {
                        next = min(next, dp[r][c+1]);
                    }
                    cellNew -= next;
                }
                int cur =abs(min(cellNew, 0));
//                if(vv[r][c] <= 0) {
//                    cur+=1;
//                }
                //cur = max(cur, 1);
                dp[r][c] = cur;
            }
        }
        //printVV(dp);
        res = dp[0][0];
        res += 1;
        return res;
    }
    
    
    
    
    int getMinDfs(vector<vector<int>>& vv, int M, int N) {
        int point = 0;
        int cur=0;
        int res=INT32_MAX;
        dfs(vv, 0, 0, M, N, point, cur, res);
        
        res = max(1, res);

        return res;
    }
    
    void dfs(vector<vector<int>>& vv, int i, int j, int M, int N, int point, int cur, int & res) {
        point += vv[i][j];
        
        //        cout << "i, j:" << i << "\t" << j << endl;
        if(point <= 0) {
            int num = abs(point)+1;
            cur += num;
            point = 1;
            //            cout << "cur:" << cur << endl;
        }
        
        
        if(i == M-1 && j == N-1) {
            res = min(res, cur);
            //            cout << "res:" << res << endl;
            return;
        }
        
        if(cur >= res) {
            return;
        }
        
        //right
        if( i < M-1) {
            dfs(vv, i+1, j, M, N, point, cur, res);
        }
        
        //down
        if( j < N-1) {
            dfs(vv, i, j+1, M, N, point, cur, res);
        }
        
    }
    
    void printVV(vector<vector<int>> & vv) {
        int M = vv.size();
        int N = vv[0].size();
        for(int r=0; r < M; r++) {
            for(int c=0; c < N; c++) {
                cout << vv[r][c] << "\t";
            }
            cout << endl;
        }
    }
};



int main() {
    Solution sol = Solution();

    vector<vector<int>> vv;
    vv.push_back(vector<int>({-2,-3,3}));
    vv.push_back(vector<int>({-5,-10,1}));
    vv.push_back(vector<int>({10,30,-5}));



    int res = sol.calculateMinimumHP(vv);

    cout << res << endl;

    
    return 0;
}



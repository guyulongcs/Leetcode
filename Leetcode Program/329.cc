#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxLen=0;
        
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dfs(matrix, m, n, dp, maxLen);
        return maxLen;
    }
    
    void dfs(vector<vector<int>>& matrix, int m, int n, vector<vector<int>> dp, int & maxLen) {
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                dfs_pos(matrix, m, n, dp, maxLen, i, j, INT32_MIN);
            }
        }
    }
    
    int dfs_pos(vector<vector<int>>& matrix, int m, int n, vector<vector<int> >& dp, int & maxLen, int r, int c, int preNum) {
        if(r < 0 || r >= m || c < 0 || c >= n || (matrix[r][c] <= preNum))
            return 0;
        
        if(dp[r][c] != 0)
            return dp[r][c];
        
        //up
        int lu = dfs_pos(matrix, m, n, dp, maxLen, r-1, c, matrix[r][c]);
        
        //down
        int ld= dfs_pos(matrix, m, n, dp, maxLen, r+1, c, matrix[r][c]);
        
        //left
        int ll = dfs_pos(matrix, m, n, dp, maxLen, r, c-1, matrix[r][c]);
        
        //right
        int lr = dfs_pos(matrix, m, n, dp, maxLen, r, c+1, matrix[r][c]);
        
        int lnei = max(max(lu, ld), max(ll, lr));
        
        dp[r][c] = 1 + lnei;
        
        maxLen = max(maxLen, dp[r][c]);

        return dp[r][c];
    }
    
    
    void printV(vector<int> v) {

        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    void printVV(vector< vector<int> > vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
};

int main() {

    Solution s;
   

    vector< vector<int> > vv;
    vv.push_back(vector<int>{9,9,4});
    vv.push_back(vector<int>{6,6,8});
    vv.push_back(vector<int>{2,1,1});
    
    int res = s.longestIncreasingPath(vv);
    cout << res << endl;
    return 0;
}


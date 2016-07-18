#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        dfs(grid, m, n, res);
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int m, int n, int & res) {
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                char ch = grid[i][j];
                if(ch == '1' && !visit[i][j]) {
                    dfs_visit(grid, visit, m, n, i, j);
                    res++;
                }
            }
        }
    }
    
    void dfs_visit(vector<vector<char>> & grid, vector<vector<bool>> & visit, int m, int n, int i, int j) {
        visit[i][j] = true;
        //left
        dfs_visit_next(grid, visit, m, n, i, j-1);
        //right
        dfs_visit_next(grid, visit, m, n, i, j+1);
        //up
        dfs_visit_next(grid, visit, m, n, i-1, j);
        //down
        dfs_visit_next(grid, visit, m, n, i+1, j);
    }
    
    void dfs_visit_next(vector<vector<char>> & grid, vector<vector<bool>> & visit, int m, int n, int i, int j) {
        if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1' && !visit[i][j]) {
            dfs_visit(grid, visit, m, n, i, j);
        }
    }
};


int main() {

    Solution s;
    vector<vector<char>> vv;
    vv.push_back(vector<char>{'1','1','1','1','0'});
    vv.push_back(vector<char>{'1','1','0','1','0'});
    vv.push_back(vector<char>{'1','1','0','0','0'});
    vv.push_back(vector<char>{'0','0','0','0','0'});

    int res = s.numIslands(vv);
    cout << res << endl;
    
    return 0;
}

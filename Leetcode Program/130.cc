#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        char chDefault = 'X';
        char chReplace = 'O';
        char chMark = 'M';
        if(board.size() == 0 || board[0].size() == 0)
            return;
        
        int m = (int)board.size();
        int n = (int)board[0].size();
        
        //get region
        getRegion(board, m, n, chReplace, chMark);
        
        //printVV(board);
        
        //update region
        update(board, m, n, chDefault, chReplace, chMark);
    }
    
    void getRegion(vector<vector<char>>& board, int m, int n, char chReplace, char chMark) {
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                if((i==0 || i == m-1) || (j==0 || j == n-1)) {
                    
                    if(board[i][j] == chReplace) {
//                        cout << "i, j:" << i << "\t" << j << endl;
                        //dfs(board, m, n, i, j, chReplace, chMark);
                        board[i][j] = chMark;
                        bfs(board, m, n, i, j, chReplace, chMark);
                    }
                }
            }
        }

    }
    
    void bfs(vector<vector<char>>& board, int m, int n, int r, int c, char chReplace, char chMark) {
        if(r < 0 || r >= m || c <0 || c >= n)
            return;
        
//        if(board[r][c] != chReplace)
//            return;
        
        
        queue<int> q;
        int id = getLocId(n, r, c);
        q.push(id);
        
        while(!q.empty()) {
            int id = q.front();
            getLocFromId(id, n, r, c);
            q.pop();
            
            board[r][c] = chMark;
            for(int i=-1; i <= 1; i++) {
                for(int j=-1; j <= 1; j++) {
                    int rn = r+i;
                    int cn = c+j;
                    if(abs(i) + abs(j) == 1) {
                        if(!isValidLoc(m, n, rn, cn))
                            continue;
                        if(board[rn][cn] == chReplace) {
                            board[rn][cn] = chMark;
                            int nextId = getLocId(n, rn, cn);
                            q.push(nextId);
                        }
                    }
                }
            }
        }
        
    }
    
    bool isValidLoc(int m, int n, int r, int c) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
    
    int getLocId(int n, int r, int c) {
        return r*n+c;
    }
    
    void getLocFromId(int id, int n, int & r, int & c) {
        r = id / n;
        c = id % n;
    }
    
    
    
    
    void dfs(vector<vector<char>>& board, int m, int n, int r, int c, char chReplace, char chMark) {
        
        if(r < 0 || r >= m || c <0 || c >= n)
            return;
        
        if(board[r][c] != chReplace)
            return;
        
        board[r][c] = chMark;
        for(int i=-1; i <= 1; i++) {
            for(int j=-1; j <= 1; j++) {
                int rn = r+i;
                int cn = c+j;
                if(abs(i) + abs(j) == 1) {
                    dfs(board, m, n, rn, cn, chReplace, chMark);
                }
            }
        }
    }
    
    void update(vector<vector<char>>& board, int m, int n, char chDefault, char chReplace, char chMark) {
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                if(board[i][j] == chReplace) {
                    board[i][j] = chDefault;
                }
                else if(board[i][j] == chMark) {
                    board[i][j] = chReplace;
                }
            }
        }
    }
    
    void printVV(vector<vector<char>>& vv) {
        cout << endl;
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
    
    void printV(vector<char>& v) {
        
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    void setVV(vector<vector<char>> & vv, vector<string> & vs) {
        for(int i=0; i < vs.size(); i++) {
            vector<char> v;
            for(int j=0; j < vs[i].length(); j++) {
                v.push_back(vs[i][j]);
            }
            vv.push_back(v);
        }
    }
};


int main() {
    Solution sol;
   
    vector<vector<char>> vv;
//    vv.push_back(vector<char>({'X','X','X','X'}));
//    vv.push_back(vector<char>({'X','O','O','X'}));
//    vv.push_back(vector<char>({'X','X','O','X'}));
//    vv.push_back(vector<char>({'X','O','X','X'}));
    
    vector<string> vs = vector<string>( {"OOOOOOOOXOOOOOXOOOOO","OOOOOOOXOOOOOOOOOOOO","XOOXOXOOOOXOOXOOOOOO","OOOOOOOOOOOOOOOOOXXO","OXXOOOOOOXOOOOOOOOOO","OOOOXOOOOOOXOOOOOXXO","OOOOOOOXOOOOOOOOOOOO","OOOOOOOOOOOOOXOOOOOO","OOOOOOOOOOOOOOOOOOXO","OOOOOXOOOOOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","OOOOXOOOOXOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","XOOOOOOOOXXOOOOOOOOO","OOOOOOOOOOOXOOOOOOOO","OOOOXOOOOOOOOXOOOOOX","OOOOOXOOOOOOOOOXOXOO","OXOOOOOOOOOOOOOOOOOO","OOOOOOOOXXOOOXOOXOOX","OOOOOOOOOOOOOOOOOOOO"
    }
    );
    
    sol.setVV(vv, vs);
    
    sol.printVV(vv);
    sol.solve(vv);
    sol.printVV(vv);
    
    
    
    return 0;
}


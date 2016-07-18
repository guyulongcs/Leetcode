#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return false;
        
        int M = board.size();
        int N = board[0].size();
        
        vector<vector<bool>> p(M, vector<bool>(N, false));
        
        int len = word.length();
        if(len == 0)
            return true;
        
//        if(len > M*N)
//            return false;
        bool flag = solve(board, p, M, N, word, 0, len-1);
        return flag;
    }
    
    
    bool solve(vector<vector<char>>& board, vector<vector<bool>> & p, int M, int N, string & word, int s, int e) {
       
        //cout << "s, e:" << s << "\t" << e << endl;
        if(s > e)
            return true;
        
        bool flag = false;
        char ch = word[s];
        for(int i=0; !flag && i < M; i++) {
            for(int j=0; !flag && j < N; j++) {
                if(!p[i][j] && board[i][j] == ch) {
                    p[i][j] = true;
                    bool flagNext = solveNext(board, p, M, N, word, s+1, e, i, j);
                    if(flagNext) {
                        flag = true;
                    }
                    p[i][j] = false;
                }
            }
        }
        return flag;
        
    }
    
    bool isValid(vector<vector<char>>& board, vector<vector<bool>> & p, int M, int N, int i, int j, char ch) {
        bool flag = false;
        if(i >= 0 && i < M && j >= 0 && j < N && !p[i][j] && board[i][j] == ch)
            flag = true;
        return flag;
    }
    
    bool solveNext(vector<vector<char>>& board, vector<vector<bool>> & p, int M, int N, string & word, int s, int e, int i, int j) {
        //cout << "s, e:" << s << "\t" << e << endl;
        bool flag = false;
        
        if(s > e)
            return true;
        
        int r;
        int c;
        char ch = word[s];
        //left
        if(isValid(board, p, M, N, i-1, j, ch)) {
            p[i-1][j] = true;
            if(solveNext(board, p, M, N, word, s+1, e, i-1, j)) {
                return true;
            }
            p[i-1][j] = false;
        }
        //right
        if(isValid(board, p, M, N, i+1, j, ch)) {
            p[i+1][j] = true;
            if(solveNext(board, p, M, N, word, s+1, e, i+1, j)) {
                return true;
            }
            p[i+1][j] = false;
        }
        //up
        if(isValid(board, p, M, N, i, j-1, ch)) {
            p[i][j-1] = true;
            if(solveNext(board, p, M, N, word, s+1, e, i, j-1)) {
                return true;
            }
            p[i][j-1] = false;
        }
        
        //down
        if(isValid(board, p, M, N, i, j+1, ch)) {
            p[i][j+1] = true;
            if(solveNext(board, p, M, N, word, s+1, e, i, j+1)) {
                return true;
            }
            p[i][j+1] = false;
        }
        
        return false;
    }
};

void printVecInt(vector<int> & v) {
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

int main() {


    vector<vector<char>> vv;
    vv.push_back(vector<char>({'a','a','a','a'}));
    vv.push_back(vector<char>({'a','a','a','a'}));
    vv.push_back(vector<char>({'a','a','a','a'}));
    
    string str = "aaaaaaaaaaaaa";
    Solution s;
    bool flag = s.exist(vv, str);
    cout << str << "\t" << flag << endl;
    
    return 0;
}


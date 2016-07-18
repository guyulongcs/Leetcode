#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    
    void solveSudoku(vector<vector<char>>& board) {
        bool flagSolved = false;
        if(board.size() == 0 || board[0].size() == 0) {
            return;
        }
        
        int M = (int)board.size();
        int N =  (int)board[0].size();
        
        cout << "M, N:" << M << "\t" << N << endl;
        solve(board, M, N, 0);
    }
    
    void printSet(set<char> & s) {
        for(auto it = s.begin(); it != s.end(); it++) {
            char ch = *it;
            cout << ch << "\t";
        }
        cout << endl;
    }
    
    bool solve(vector<vector<char>>& board, int M, int N, int pos) {
        
        int r = pos / N;
        int c = pos % N;
        
//        cout << "r,c:" << r << "\t" << c << endl;
        //cout << "pos:" << pos << endl;
        if(pos >= M * N)
            return true;
        
        if(board[r][c] == '.') {
            for(char ch = '1'; ch <= '9'; ch++) {
                if(isValidPosNum(board, M, N, r, c, ch)) {
                    board[r][c] = ch;
                    if(solve(board, M, N, pos+1))
                        return true;
                    board[r][c] = '.';

                }
            }
            return false;
        }
        else {
            bool flag = solve(board, M, N, pos+1);
            if(flag)
                return true;
        }

        return false;
    }
    
    
    bool findFirstEmpty(vector<vector<char>>& board, int M, int N, int rs, int cs, int & rem, int & cem) {
        bool flag = false;
        for(int r=rs; !flag && r < M; r++) {
            for(int c=0; !flag && c < N; c++) {
                if(board[r][c] == '.') {
                    flag = true;
                    rem = r;
                    cem = c;
                    break;
                }
            }
        }
        return flag;
    }
    
    bool isValidPosNum(vector<vector<char>>& board, int M, int N, int r, int c, char ch) {
        bool flag = true;
        
        for(int i=0; i < N; i++) {
            if(i != c && board[r][i] == ch) {
                return false;
            }
        }
        
        for(int i=0; i < M; i++) {
            if(i != r && board[i][c] == ch) {
                return false;
            }
        }
        
        int gr = r/3;
        int gc = c/3;
        
        for(int i=3*gr; i < 3*gr+3; i++) {
            for(int j=3*gc; j < 3*gc+3; j++) {
                if(i == r && j == c)
                    continue;
                if(board[i][j] == ch) {
                    return false;
                }
            }
        }
        
        return flag;
    }
    
    void getInputData(vector<string> & vs, vector< vector<char> > & v) {
        for(int i=0; i < vs.size(); i++) {
            string str = vs[i];
            vector<char> vc;
            for(int j=0; j < str.length(); j++) {
                vc.push_back(str[j]);
            }
            v.push_back(vc);
        }
    }
    
    void printV(vector<char> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    void printVV( vector< vector<char> >  & vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
};


int main() {


    Solution s;


    vector< vector<char> > v;

    vector<string> vs;
    vs.push_back("53..7....");
    vs.push_back("6..195...");
    vs.push_back(".98....6.");
    vs.push_back("8...6...3");
    vs.push_back("4..8.3..1");
    vs.push_back("7...2...6");
    vs.push_back(".6....28.");
    vs.push_back("...419..5");
    vs.push_back("....8..79");
    


    s.getInputData(vs, v);
    
    s.solveSudoku(v);
    

    s.printVV(v);

    return 0;
}


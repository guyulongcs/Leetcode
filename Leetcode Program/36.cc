#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    
    bool isValidSudoku(vector< vector<char> >& board) {
        
        if(board.size() == 0 || board[0].size() == 0) {
            //cout << "None" << endl;
            return true;
        }
        
        
        bool flag = true;
        flag = isValidSudokuHori(board);

//        cout << "flag:" << flag << endl;
        if(flag) {
            flag =isValidSudokuVert(board);
        }
//        cout << "flag:" << flag << endl;
        if(flag)
            flag =isValidSudokuSquare(board);
//        cout << "flag:" << flag << endl;
        
        return flag;
    }
    
    bool isValidSudokuHori(vector< vector<char> >& board) {
        bool flag = true;
        for(int i=0; flag && i < board.size(); i++) {
            vector<bool> fDigit(10, false);
            for(int j=0; j < board[i].size(); j++) {
                char ch = board[i][j];
                if(isdigit(ch)) {
                    int num = ch-'0';
                    if(!isValidNum(num) || fDigit[num]) {
                        flag = false;
                        break;
                    }
                    fDigit[num] = true;
                }
            }
        }
        return flag;
    }
    
    bool isValidNum(int num) {
        return (num >= 1 && num <= 9);
    }
    
    bool isValidSudokuVert(vector <vector<char> >& board) {
        bool flag = true;
        
        int M = (int)board.size();
        int N =  (int)board[0].size();
        
        for(int i=0; flag && i < N; i++) {
            vector<bool> fDigit(10, false);
            for(int j=0; j < M; j++) {
                char ch = board[j][i];
                if(isdigit(ch)) {
                    int num = ch-'0';
                    if(!isValidNum(num) || fDigit[num]) {
                        flag = false;
                        break;
                    }
                    fDigit[num] = true;
                }
            }
        }
        return flag;
    }
    
    bool isValidSudokuSquare(vector <vector<char> >& board) {
        bool flag = true;
        
        int M =  (int)board.size();
        int N =  (int)board[0].size();
        
        for(int i=0; flag && i < M; i+=3) {
            for(int j=0; flag && j < N; j+=3) {
                if(!isValidSudokuOneSquare(board, i, j)) {
//                    cout << "Invalid:" << i << "\t" << j << endl;
//                    cout << "board[i][j]:"<< board[i][j] << endl;
                    flag = false;
                    break;
                }
            }
        }
        
        return flag;
    }
    
    bool isValidSudokuOneSquare(vector< vector<char> >& board, int r, int c) {
        bool flag = true;
        vector<bool> fDigit(10, false);
        int M =  (int)board.size();
        int N =  (int)board[0].size();
//        cout << "M, N:" << M << "\t" << N << endl;
//        cout << "r, c:" << r << "\t" << c << endl;
        for(int i=r; flag && i < r+3; i++) {
            for(int j=c; flag && j < c+ 3; j++) {
//                cout << "i, j:" << i << "\t" << j << endl;
                if(!isValidPos(M, N, i, j)) {
                    continue;
                }
                char ch = board[i][j];
//                cout << "ch:" << ch << endl;
                
                if(isdigit(ch)) {
                    int num = ch-'0';
                    if(!isValidNum(num) || fDigit[num]) {
                        flag = false;
                        break;
                    }
                    fDigit[num] = true;
                }
            }
        }
//        cout << "flag:" << flag << endl;
        return flag;
    }
    
    bool isValidPos(int M, int N, int r, int c) {
        bool flag = true;
        
        if(r < 0 || r >= M) {
            flag = false;
        }
        if(c < 0 || c >= N) {
            flag = false;
        }
        
//        cout << "r, M:" << r << "\t" << M << endl;
//        cout << "flag222:" << flag << endl;
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
};


int main() {


    Solution s;
    

    vector< vector<char> > v;
    
    vector<string> vs;
    vs.push_back("..5.....6");
    vs.push_back("....14...");
    vs.push_back(".........");
    vs.push_back(".....92..");
    vs.push_back("5....2...");
    vs.push_back(".......3.");
    vs.push_back("...54....");
    vs.push_back("3.....42.");
    vs.push_back("...27.6..");


    s.getInputData(vs, v);
    
    bool flag = s.isValidSudoku(v);
    cout << flag << endl;


    return 0;
}


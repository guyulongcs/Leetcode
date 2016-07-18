#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    //00:0, 11: 1, 10:2, 01:3
    void gameOfLife(vector< vector<int> >& board) {
        if(board.size()==0 || board[0].size()==0)
            return;
        
        int R = board.size();
        int C = board[0].size();
        //cout << R << " " << C << endl;
        
        for(int r=0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                int newValue = getNewUnit(board, R, C, r, c, true);
                board[r][c] = newValue;
                //cout << "newValue:" << newValue << endl;
            }
        }
        
        for(int r=0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                board[r][c] = (board[r][c] == 1 || board[r][c] == 3);
            }
        }
    }
    
    void gameOfLifeCopy(vector<vector<int> >& board) {
        vector<vector<int> > newBoard;
        int R =0;
        int C=0;
        R=board.size();
        if(R > 0)
            C= board[0].size();
        
        for(int r=0; r < R; r++) {
            vector<int> newRow;
            
            for(int c=0; c < C; c++) {
                int newValue = getNewUnit(board, R, C, r, c);
                newRow.push_back(newValue);
            }
            newBoard.push_back(newRow);
        }
        board = newBoard;
    }
    


    
    int getNewUnit(vector<vector<int> >& board, int R, int C, int r, int c, bool notCopy = false) {
        int newValue = 0;
        
        int neiOneCnt = getNeiOneCnt(board, R, C, r, c, notCopy);
        
        //cout << "row:" << r << ", col:" << c << ", neiOneCnt: " << neiOneCnt << endl;

        
        int oldValue = board[r][c];
        newValue = oldValue;
        
        bool alive = isAlive(oldValue, notCopy);
        if(alive) {
            if(neiOneCnt < 2 || neiOneCnt > 3) {
                if(notCopy == false)
                    newValue = 0;
                else {
                    newValue = 2;
                }
            }
            
        }
        else {
            if(neiOneCnt == 3)
                if(notCopy == false)
                    newValue = 1;
                else {
                    newValue = 3;
                }
        }
        
        
        return newValue;
    }
    
    bool isAlive(int value, bool notCopy=false) {
        bool flag = false;
        if(notCopy) {
            flag = (value == 1 || value == 2);
        }
        else {
            flag = (value == 1);
        }
        return flag;
    }
    
   
    int getNeiOneCnt(vector<vector<int> >& board, int R, int C, int r, int c, bool notCopy = false) {
        int cnt=0;
        
        for(int i=-1; i <= 1; i++) {
            for(int j=-1; j <= 1; j++) {
                if(i==0 and j==0)
                    continue;
                cnt +=  intUnitOne(board, R, C, r+i, c+j, notCopy);
            }
        }
        //cout << "getNeiOneCnt:" << r << "," << c << "\t" << cnt << endl;

        return cnt;
    }
    
    int intUnitOne(vector<vector<int> >& board, int R, int C, int r, int c, bool notCopy = false) {
        int cnt=0;
        if(isUnitOne(board, R, C, r,c, notCopy))
           cnt=1;
        
        //cout << "intUnitOne:" << r << "," << c << "\t" << cnt << endl;
        return cnt;
    }
    
    bool isUnitOne(vector<vector<int> >& board, int R, int C, int r, int c, bool notCopy = false) {
        bool flag=false;
        if((r >=0) and (r <= R-1) and (c>=0) and (c <= C-1)) {
            if(notCopy == false and (board[r][c] == 1))
                flag = true;
            if(notCopy == true and ((board[r][c] == 1) || (board[r][c] == 2)))
                flag = true;
        }
        
        
        return flag;
    }
    
    void printBoard(vector<vector<int> >& board) {
        for(int i=0; i < board.size(); i++) {
            string line = "";
            for(int j=0; j < board[i].size(); j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
        
    }
    

    
};

int main() {
    Solution s = Solution();
    int res = 0;
    
    int a[2][2] = {
        {1,1},
        {1,0},
    
    };
    vector<vector<int> > board;
    vector<int> v1(a[0], a[0]+2);
    vector<int> v2(a[1], a[1]+2);
    
    board.push_back(v1);
    board.push_back(v2);
   
    
    s.printBoard(board);
    s.gameOfLife(board);
    
    s.printBoard(board);
    
    
    return 0;
}


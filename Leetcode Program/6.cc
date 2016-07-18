#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


 

class Solution {
private:
    unordered_map<char, string> map;
public:
    string convert(string s, int numRows) {
        string res;
        int N = s.length();
        if(N==0)
            return res;
        
        if(numRows == 1)
            return s;
        
        const char CHEMPTY='\0';
        vector< vector<char> > vv(numRows, vector<char>(N+1, CHEMPTY));
        
        
        int i=0;
        int row = 0;
        int col = 0;
        bool flagDown = true;
        for( i=0; i < N; i++) {
            cout << "row:" << row << ",col:" << col << endl;
            vv[row][col] = s[i];
            nextRowCol(row, col, numRows, flagDown);
        }
        
        
        for(int i=0; i < numRows; i++) {
            for(int j=0; j <= col; j++) {
                if(vv[i][j] != '\0') {
                    res = res + charToString(vv[i][j]);
                }
            }
        }
        return res;
    }
    
    string charToString(char ch) {
        char a[2];
        a[0]=ch;
        a[1]='\0';
        string s(a);
        return s;
    }
    
    void nextRowCol(int &row, int & col, int numRows, bool & flagDown) {
        if(flagDown) {
            if(numRows == 2) {
                row++;
                if(row >= numRows) {
                    row=0;
                    col++;
                }
                return;
            }
            if(row == numRows-1) {
                row = numRows-2;
                flagDown = false;
                col++;
            }
            else {
                row++;
            }
        }
        else {
            if(row == 1) {
                row =0;
                flagDown = true;
                col++;
            }
            else {
                row--;
            }
        }
        
    }
};


int main() {

    Solution s;
    
    string res = s.convert("ABCDEFGHIJKLMN", 2);
    cout << res << endl;
    
    return 0;
}


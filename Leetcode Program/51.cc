#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int * a = new int[n+1];
        memset(a, 0, sizeof(int) * (n+1));
        int cnt = 0;
        queen(a, n, 1, cnt);
        
        return cnt;
    }
    
    vector< vector<string> > solveNQueens(int n) {
        vector< vector<string> > res;
        int * a = new int[n+1];
        memset(a, 0, sizeof(int) * (n+1));
        int cnt = 0;
        queenPlace(a, n, 1, res);
        
        return res;
    }
    
    void queenPlace(int * a, int N, int n, vector< vector<string> >& res) {
        if(n > N){
            vector<string> v;
            for(int i=1; i <= N; i++) {
                int col = a[i];
                string row;
                for(int j=1; j <= N; j++) {
                    char ch = '.';
                    if(j == col)
                        ch = 'Q';
                    row += ch;
                }
                v.push_back(row);
            }
            res.push_back(v);
            return;
        }
        for(int col = 1; col <= N; col++) {
            if(isValidCol(a, n, col)) {
                a[n] = col;
                queenPlace(a, N, n+1, res);
                a[n] = 0;
            }
        }
    }

    
    void queen(int * a, int N, int n, int & cnt) {
        if(n > N){
            cnt+=1;
            return;
        }
        for(int col = 1; col <= N; col++) {
            if(isValidCol(a, n, col)) {
                a[n] = col;
                queen(a, N, n+1, cnt);
                a[n] = 0;
            }
        }
    }
    
    bool isValidCol(int * a, int r, int col) {
        
        for(int i=1; i < r; i++) {
            //cols
            if(a[i] == col) {
                return false;
            }
            //diag
            if(abs(a[i]-col) == (r-i)) {
                return false;
            }
        }
        return true;
    }
    
};

int main() {
    Solution s = Solution();
    for(int n = 4; n<=5;n++) {
        int num = s.totalNQueens(n);
         cout << n << ", "<<  num << endl;
    }
    
    int n=4;
    vector< vector<string> > res = s.solveNQueens(n);
    for(int i =0; i < res.size(); i++) {
        cout << "\nsolution" << endl;
        for(int j=0;  j < res[i].size(); j++) {
            string s=res[i][j];
            cout << s << endl;
        }
    }
    return 0;
}


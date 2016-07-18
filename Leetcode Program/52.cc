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
    for(int n = 4; n<=10;n++) {
        int num = s.totalNQueens(n);
         cout << n << ", "<<  num << endl;
    }
    return 0;
}


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class NumMatrix {
public:
    int * * s;
    int R=0;
    int C = 0;
    NumMatrix(vector< vector<int> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        R = matrix.size();
        C = matrix[0].size();
        
        s = new int * [R];
        
        for(int r=0; r < R; r++) {
            s[r] = new int[C];
            for(int c=0; c < C; c++) {
                int n1=0;
                int n2=0;
                int n3=0;
                if(r > 0)
                    n1 = s[r-1][c];
                if(c > 0)
                    n2 = s[r][c-1];
                if(r > 0 && c > 0)
                    n3 = s[r-1][c-1];
                s[r][c] = n1 + n2 - n3 + matrix[r][c];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int n1=0;
        int n2=0;
        int n3=0;
        int n4=0;
        
        if(row2 >=0 && row2 < R && col2 >=0 and col2 < C)
            n1 = s[row2][col2];
        if(row1 >=1 && row1 < R && col2 >=0 and col2 < C)
            n2 = s[row1-1][col2];
        if(row2 >=0 && row2 < R && col1 >=1 and col1 < C)
            n3 = s[row2][col1-1];
        if(row1 >=1 && row1 < R && col2 >=1 and col2 < C)
            n4 = s[row1-1][col1-1];
        
        int res = n1-n2-(n3-n4);
        return res;
        
    }
};

int main() {
    vector< vector<int> > matrix;
    int a[][5] = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    int R= 5;
    int C = 5;
    
    for(int i=0; i< R; i++) {
        vector<int> v;
        for(int j=0; j<C; j++) {
            v.push_back(a[i][j]);
        }
        matrix.push_back(v);
    }
    
    NumMatrix numM(matrix);

    
    
    int res = 0;
    res = numM.sumRegion(0,0,0,0);
    cout << res << endl;
    return 0;
}

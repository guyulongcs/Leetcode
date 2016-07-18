#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    int maximalSquare(vector< vector<char> >& matrix) {
        if(matrix.size()==0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector< vector<int> > d(2, vector<int>(n+1, 0));
        
        int maxL = 0;
        for(int i=1; i <= m; i++) {
            for(int j=1; j <= n; j++) {
                if(matrix[i-1][j-1] == '1') {
                    d[1][j] = min(min(d[0][j-1], d[0][j]), d[1][j-1]) + 1;
                    maxL = max(maxL, d[1][j]);
                }
                else {
                    d[1][j] = 0;
                }
            }
            for(int j=1; j <= n; j++) {
                d[0][j] = d[1][j];
            }
        }
        int maxArea = maxL * maxL;
        return maxArea;
        
        
    }
//    
//    int min(int a, int b) {
//        int res=(a < b) ? a: b;
//        return res;
//    }
    
    int maximalSquare1(vector< vector<char> >& matrix) {
        if(matrix.size()==0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
//        cout << m << ","<< n <<endl;
    
        
        vector< vector<int> > a(m, vector<int>(n, 0));
        vector< vector<int> > b(m, vector<int>(n, 0));
        
   
        
        int maxArea= 0;
        int maxk = 0;
        for(int i=0; i < m; i++){
            for(int j=0 ; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0)
                        a[i][j] = 1;
                    else
                        a[i][j] = a[i-1][j] + 1;
                       
                    if(j == 0)
                        b[i][j] = 1;
                    else
                       b[i][j] = b[i][j-1] + 1;
                }
                else{
                    a[i][j] = 0;
                    b[i][j] = 0;
                }
                
                int k = min(a[i][j], b[i][j]);
//                cout << "i, j, k:" << i <<"\t" << j <<"\t" << k << endl;
//                cout <<"a[j], b[j]:" << a[j] << "\t" << b[j] << endl << endl;

                if(k > maxk) {
                    k = getMaxLenth(a, b, i, j, k);
//                    cout << "k:" << k << endl;
                    if(k > maxk) {
                        maxk = k;
                    }
                }
                        
            }
        }
        
        maxArea = maxk * maxk;
        
        return maxArea;
    }
    
    int getMaxLenth(vector< vector<int> > a, vector< vector<int> > b, int i, int j, int k) {
        int r=k;
//        cout << "getMaxLenth" << endl;
        for(r=k; r >=1; r--) {
            bool flag = true;
            if(a[i][j-k+1] < k || b[i-k+1][j] < k)
                flag = false;
            if(flag == true)
                break;
        }
        return r;
    }
    
    int maximalSquare2(vector< vector<char> >& matrix) {
        if(matrix.size()==0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        //        cout << m << ","<< n <<endl;
        
        
        vector< int > a(n, 0);
        vector< int > b(n, 0);
        
        
        
        int maxArea= 0;
        int maxk = 0;
        for(int i=0; i < m; i++){
            for(int j=0 ; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0)
                        a[j] = 1;
                    else
                        a[j] = a[j] + 1;
                    
                    if(j == 0)
                        b[j] = 1;
                    else
                        b[j] = b[j-1] + 1;
                }
                else{
                    a[j] = 0;
                    b[j] = 0;
                }
                
                int k = min(a[j], b[j]);
//                cout << endl << "i, j, k:" << i <<"\t" << j <<"\t" << k << endl;
//                cout <<"a[j], b[j]:" << a[j] << "\t" << b[j] << endl << endl;
//                
                if(k > maxk) {
                    k = getSquareMaxLenth(matrix, a, b, i, j, k);
//                    cout << "k:" << k << endl;
                    if(k > maxk) {
                        maxk = k;
                    }
                }
                
            }
        }
        
        maxArea = maxk * maxk;
        
        return maxArea;
    }

    int getSquareMaxLenth(vector< vector<char> >& matrix, vector< int > a, vector< int > b, int i, int j, int k) {
        int r=k;
//                cout << "getMaxLenth" << endl;
        for(r=k; r >=1; r--) {
            bool flag = true;
           
            for(int p = j-r+1; p <= j; p++) {
                if(a[p] < r) {
                    flag = false;
                    break;
                }
            }
            
            if(flag == true)
                break;
        }
        return r;
    }
};

int main() {
    
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    Solution s;


    int m=3;
    int n=3;
    int aa[][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    int res = 0;
    
    
    vector< vector<char> > matrix(6, vector<char>(6,'1'));
    matrix[0][1] = matrix[0][4] = '0';
 
    matrix[2][0] = matrix[2][3] = '0';
    matrix[3][3] = matrix[3][5] = '0';
    matrix[4][0] = '0';
    matrix[5][2] = '0';
    
    res =s.maximalSquare(matrix);
    cout << res << endl;
    return 0;
}

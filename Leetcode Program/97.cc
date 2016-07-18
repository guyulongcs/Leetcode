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
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if(l1==0 && l2==0 && l3==0)
            return true;
        
        if(l1 == 0)
            return s2==s3;
        
        if(l2==0)
            return s1==s3;
        
        if(l1 + l2 != l3)
            return false;
        
        bool flag = true;
        
        vector< vector<bool> > a(l1+1, vector<bool>(l2+1, false));
        
        int i1, i2, i3;
        
//        cout << "l:" << l1 << "," << l2 << "," << l3 << endl;
        
        for(int i2=l2-1; i2>=0; i2--) {
            a[l1][i2] = (s2.substr(i2) == s3.substr(l1+i2));
//            cout << a[l1][i2] << "\t";
        }
//        cout << endl;
        
        for(int i1=l1-1; i1>=0; i1--) {
            a[i1][l2] = (s1.substr(i1) == s3.substr(l2+i1));
//            cout << a[i1][l2] << "\t";
        }
//        cout << endl;
        
        for(i1=l1-1; flag && i1>=0; i1--) {
            
            for(i2 = l2-1; flag && i2 >=0; i2--) {
                i3 = i1 + i2 ;
//                cout << "i3:" << i3 << endl;
                
//                if(s1[i1] != s3[i3] && s2[i2] != s3[i3]) {
//                    flag = false;
//                    break;
//                }
                bool flag1=false;
                bool flag2=false;
                if(s1[i1] == s3[i3]) {
                    flag1 = a[i1+1][i2];
                }
                if(s2[i2] == s3[i3]) {
                    flag2 = a[i1][i2+1];
                }
               
                a[i1][i2] = flag1 || flag2;
//                cout << "flag:" << flag1 << "\t" << flag2 << endl;
//                cout << i1 << "," << i2 << ":" << a[i1][i2] << endl;
            }
        }
        
        if(flag) {
            flag = a[0][0];
        }
        
        return flag;
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
    
    string s1,s2,s3,s4;
    s1= "acb";
    s2= "bd";
    s3= "bacdb";
    s4="aa";
    
    
   
    
    
    res =s.isInterleave(s1,s2,s3);
    cout << res << endl;
    
//    res =s.isInterleave(s1,s2,s4);
//    cout << res << endl;
    
    return 0;
}


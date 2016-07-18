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
    int myAtoi(string s) {

        int n = s.length();
        if(n == 0)
            return 0;
        
        bool fValid = true;
        bool fNeg = false;
        long long res = 0;
        
        bool fHasNum = false;
        
        
 
        for(int i=0; i<n; i++) {
            cout << "s[i]:" << s[i] << endl;
            if(s[i] == ' ' ) {
                
                
                if(fHasNum == false)
                    continue;
                else {
//                    fValid = false;
                    break;
                }
            }
            
//            if(fValid == false)
//                break;
//        
            if(fHasNum == false) {
                if( s[i] == '-') {
                    fHasNum = true;
                    fNeg = true;
                    continue;
                }
                if(s[i] == '+') {
                    fHasNum = true;
                    continue;
                }
            }
            
            
            if(isdigit(s[i]) == false) {
                break;
            }
            fHasNum = true;
            int num = s[i] - '0';
            long long ores = res;
            res = res * 10 + num;
            if( !fNeg && res > INT32_MAX) {
                res = INT32_MAX;
                break;
            }
            
            
//            cout << "res:" << res << endl;
            if( fNeg  && res > (INT32_MAX)) {
                res = INT32_MAX + 1;
                break;
            }
        }
        
        if(fNeg) {
            res = -res;
        }
        
        if(!fValid)
            res = 0;
        
        
        
        int r= res;
        
        return r;
    }
 
};


int main() {
    
    cout << INT32_MAX << endl;
    Solution s;
    
    vector<string> v({" 123 456"});
    string str= "  -0012a42";
    
    
    for(int i=0; i<v.size();i++) {
        str = v[i];
        int res = s.myAtoi(str) ;
    
        cout  <<str << "\t" << res << endl;
    }


    return 0;
}


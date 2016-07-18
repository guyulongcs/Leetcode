#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;


class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        string str = int2string(n);
        
        
        int res=countDigitOneStr(str);
        return res;
    }
    
    string int2string(int n) {
        char arr[100];
        sprintf(arr, "%d", n);
        
        string str = string(arr);
        //cout << str << endl;

        return str;
    }
    
    int string2int(string str) {
        int res = atoi(str.c_str());
        return res;
    }
    
    int countDigitOneStr(string str) {
        int res=0;
        int N = str.length();
    
        for(int i=0; i < N; i++) {
            string left = str.substr(0, i);
            string right = str.substr(i+1);
            int ileft = string2int(left);
            int iright = string2int(right);
            int cur=0;
            int lright = right.length();
            int cright = pow(10, lright);
            
            if(str[i] > '1') {
                cur = (ileft+1) * cright;
            }
            else if(str[i] == '1') {
                cur = ileft * (cright);
                cur += (iright+1);
            }
            else {
                cur = ileft * cright;
            }
            res+= cur;
        }
        
        return res;
    }
    
    int countDigitOne2(int n) {
        
        int res=0;
        for(int i=1; i <= n; i++) {
            int cur = countDigitOneOfNum(i);
            res += cur;
        }
        return res;
    }
    
    int countDigitOneOfNum(int n) {
        string str = int2string(n);
        int cnt=0;
        for(int i=0; i < str.length(); i++) {
            if(str[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }
    
};

int main() {
    
    Solution s;
   
    int n = 10;
    int res;
    //res =s.countDigitOne(n);
    
    for(int i=0; i <= 2000; i++) {
        int c1 =s.countDigitOne(i);
        int c2 = s.countDigitOne2(i);
        if(c1 != c2)
        {
            cout << i << "\t" << c1 << "\t" << c2 << endl;
        }
    }
    
    
//    res =s.countDigitOne(n);
//    res = s.countDigitOne2(n);
//    cout << res << endl;
    return 0;
    
}

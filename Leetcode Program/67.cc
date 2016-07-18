nclude <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.length();
        int l2 = b.length();
        
        int i1 = l1-1;
        int i2 = l2-1;
        int c=0;
        
        string s;
        while(true) {
            int n1=0;
            int n2 =0;
            if(i1 >= 0) {
                n1 = a[i1]-'0';
                i1--;
            }
            if( i2 >= 0) {
                n2 = b[i2] - '0';
                i2--;
            }
            int n = n1+n2+c;
            int num = n%2;
            c = n /2;
            s += num+'0';
            if( i1 < 0 && i2<0 && c==0) {
                break;
            }
        }
        reverse(s.begin(), s.end());
        return s;
        
    }

};


int main() {
    

    Solution s;
    string a="";
    string b="";
    string c= s.addBinary(a,b);
    cout << c <<endl;
    


    return 0;
}


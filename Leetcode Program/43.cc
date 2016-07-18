#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string s1, string s2) {
        string res;
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n1 == 0 || n2 == 0)
            return res;
        
        if(s1 == "0" || s2 == "0")
            return "0";
            
        vector<int> v(n1+n2+1, 0);
        int j3=0;
        
        int minIndex = n1+n2;
        for(int i1=n1; i1 >= 1; i1--) {
            for(int i2=n2; i2 >= 1 ;i2--) {
                int num = (s1[i1-1]-'0') * (s2[i2-1]-'0');
                int index = i1 + i2;
                v[index] += num;
                
                while(index >= 1) {
                    int c = v[index] / 10;
                    v[index-1] += c;
                    v[index] %= 10;
                    
                    int newIndex = index;
                    if(c > 0) {
                        newIndex = index-1;
                    }
                    minIndex = min(minIndex, newIndex);
                    if(c == 0) {
                        break;
                    }
                }
            }
        }
        
        int i=0;

        for(i = minIndex; i <= n1+n2; i++) {
            res += '0' + v[i];
        }

        return res;
    }
};


int main() {
    

    Solution s;
    
    vector<string> v({" 123 456"});
    string str= "  -0012a42";
    
    
    string s1= "9";
    string s2= "9";
    
    string s3 = s.multiply(s1, s2);
    cout << s3 << endl;


    return 0;
}


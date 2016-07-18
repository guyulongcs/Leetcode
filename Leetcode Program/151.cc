#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        int N = s.length();
        
        if(N==0)
            return;
        
        reverse(s.begin(), s.end());
        int i=0;
        int j=0;
        for(; i < N; ) {
            
            for(j=i; j<N && s[j] != ' '; j++)
                ;
            reverse(s.begin()+i, s.begin() + j);
            i = j+1;
        }
        
        removeBlank(s);
    }
    
    void removeBlank(string & s) {
        string res;
        int N = s.length();
        int i=0;
        int j=0;
       
        for(; i < N; ) {
            while(i < N && s[i] == ' ')
                i++;
            for(j=i; j < N && s[j] != ' '; j++) {
                ;
            }
            if(j-i <= 0)
                continue;
            
            string word = s.substr(i, j-i);
            if(res == "")
                res = word;
            else
                res = res + " " + word;
            i = j;
        }
        s=res;
        
    }
};

int main() {
    Solution s;
    string str = "   a   b ";
    s.reverseWords(str);
    cout << str ;
    
    return 0;
}

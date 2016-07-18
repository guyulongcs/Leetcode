nclude <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int N = s.length();
        if(N==0)
            return true;
        
        bool flag = true;
        int i=0;
        int j=N-1;
        while(true) {
            
            while(i < N && !isAlphaDigit(s[i])) {
                i++;
            }
            while(j >=0 && !isAlphaDigit(s[j])) {
                j--;
            }
            if(i >= j)
                break;
            char ch1 = normCh(s[i]);
            char ch2 = normCh(s[j]);
//            cout << ch1 << "\t" << ch2 << endl;
            if(ch1 != ch2) {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        return flag;
    }
    
    bool isAlphaDigit(char ch) {
        return isLetter(ch) || isdigit(ch);
    }
    
    bool isLetter(char ch) {
        return islower(ch) || isupper(ch);
    }
    
    char normCh(char ch) {
        char res = ch;
        if(isupper(ch)) {
            res = tolower(res);
        }
        return res;
    }
};


int main() {

    Solution s;
  
    string str = "0a";
    
    bool res = s.isPalindrome(str);
    
    cout << res << endl;

    return 0;
}


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
    
    bool isValid(string s) {
        bool flag = true;
        stack<char> sc;
        for(int i=0; i  < s.length(); i++) {
            char ch = s[i];
            if(ch  == '(' || ch == '{' || ch == '[') {
                sc.push(ch);
            }
            else {
                if(sc.size() == 0) {
                    return false;
                }
                char sch = sc.top();
                if(!matchChar(ch, sch))
                    return false;
                sc.pop();
            }
                
        }
        flag = (sc.size() == 0);
        return flag;
    }
    
    bool matchChar(char ch, char sch) {
        bool flag = false;
        if(ch == ')' && sch == '(')
            flag = true;
        if(ch == '}' && sch == '{')
            flag = true;
        if(ch == ']' && sch == '[')
            flag = true;
        return flag;
        
    }
    
    
};


int main() {

    Solution s;
    
    bool res = s.isValid("(");
    cout << res << endl;
    
    return 0;
}


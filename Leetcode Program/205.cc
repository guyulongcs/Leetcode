#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;

        bool flag = true;
    
        
        int N = s.length();
        for(int i=0; i < N; i++) {
            char cs = s[i];
            char ct = t[i];
//            cout << "cs:" <<cs << ",ct:" << ct << endl;
            
            if(map1.find(cs) == map1.end()) {
                if(map2.find(ct) == map2.end()) {
                    map1[cs] = ct;
                    map2[ct] = cs;
                }
                else {
                    flag = false;
                    break;
                }
            }
            else {
                if(map1[cs] != ct) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};


int main() {
    

    Solution s;
    string s1="abc";
    string s2="def";
    
    bool flag = s.isIsomorphic(s1, s2);
    cout << flag << endl;
    
    
    return 0;
}


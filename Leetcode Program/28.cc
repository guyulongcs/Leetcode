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
    int strStr(string haystack, string needle) {
        int lh = haystack.length();
        int ln = needle.length();
        
        int res = -1;
        for(int i=0; i <= lh-ln; i++) {
            string s = haystack.substr(i, ln);
            if(s == needle) {
                res = i;
                break;
            }
        }
        
        return res;
    }
};


int main() {

    Solution s;
  
    string s1 = "";
    string s2 = "";
    
    int res = s.strStr(s1, s2);
    
    cout << res << endl;

    return 0;
}


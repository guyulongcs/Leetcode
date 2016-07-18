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
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        
        int N = strs.size();
        if(N == 0)
            return res;
        
        int j=0;
        
        bool flag = true;
        while(flag) {
            for(int i=0; i < N; i++) {
                if(j >= strs[i].length() || strs[i][j] != strs[0][j] ) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                char ch = strs[0][j];
                res += ch;
                j++;
            }
        }
        
        return res;
        
    }
};


int main() {

    Solution s;
  
    vector<string> v;
    v.push_back("ab");
    v.push_back("ac");
    v.push_back("ade");
    
    string res = s.longestCommonPrefix(v);
    
    cout << res << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int N = s.length();
        int len = 0;
        int i= N-1;
        while(i >= 0 && s[i] == ' ')
            i--;
        for(; i >=0; i--) {
            if(s[i] == ' ')
                break;
            len++;

        }
        return len;
    }
};


int main() {

    Solution s;
  
    int res = s.lengthOfLastWord("h ");
    
    cout << res << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int N = s.length();
        
        vector<int> v(257, -1);
        
        int l=0;
        int start = 0;
        for(int i=0; i < N; i++) {
            char ch = s[i];

            if(i == 0) {
                v[ch] = i;
                l=1;
                res = max(res, l);
                continue;
            }
            
            start = max(start, v[ch] + 1);
            l = i-start+1;
            v[ch] = i;
            res = max(res, l);
        }
        
        return res;
    }
};



int main() {
    Solution s= Solution();
    
    //s.testPQ();
    //return 0;
    
    string str = "abcabcbb";
   
    int res = s.lengthOfLongestSubstring(str);
    cout << res << endl;
   
    
    return 0;
}



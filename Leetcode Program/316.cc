#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0};
        int visited[256] = {0};
        string res = "0";
        for (auto a : s)
            ++m[a];
        for (auto a : s) {
            --m[a];
            if (visited[a]) continue;
            while (a < res.back() && m[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            visited[a] = 1;
        }
        return res.substr(1);
    }
    
};

int main() {
    Solution sol;
    

    string str="bcabc";
    
    
    string res = sol.removeDuplicateLetters(str);
    cout << res << endl;
    
    
    return 0;
}

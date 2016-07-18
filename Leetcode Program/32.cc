#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    int longestValidParentheses(string str) {
        int N=str.size();
        int maxL = 0;
        int cnt=0;
        stack<int> s;
        for(int i=0; i < N; i++) {
            char ch=str[i];
            if(ch == '(' ) {
                s.push(i);
            }
            else {
                if(!s.empty() && (str[s.top()] == '(')) {
                    s.pop();
                    if(s.empty()) {
                        maxL = i+1;
                    }
                    else {
                        maxL = max(maxL, i-s.top());
                    }
                }
                else {
                    s.push(i);
                }
            }
        }
       
        return maxL;
    }
};

int main() {


    Solution s;

    int res=0;

    string str= "()()";
    res =s.longestValidParentheses(str);
    cout << res << endl;


    return 0;
}


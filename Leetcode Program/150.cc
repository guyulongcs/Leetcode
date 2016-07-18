#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> snum;
    
        int N = tokens.size();
        if(N == 0)
            return 0;
        
        for(int i=0; i < N; i++) {
            string str = tokens[i];
            if(isOp(str)) {
                int n1 = snum.top();
                snum.pop();
                int n2 = snum.top();
                snum.pop();
                int res = calNum(n2, n1, str);
                snum.push(res);
            }
            else {
                int num = atoi(str.c_str());
                snum.push(num);
            }
        }
        
        int res = snum.top();
        return res;
    }
    
    int calNum(int n1, int n2, string op) {
        int n=0;
        if(op == "+") {
            n = n1 + n2;
        }
        else if(op == "-") {
            n = n1 - n2;
        }
        else if(op == "*") {
            n = n1 * n2;
        }
        else if(op == "/") {
            n = n1 / n2;
        }
        return n;
    }
    
    bool isOp(string str) {
        return (str == "+" || str == "-" || str == "*" || str == "/");
    }
    
};


int main() {


    Solution s;

    vector<string> v({"4", "13", "5", "/", "+"});
    int res = s.evalRPN(v);
    cout << res << endl;
    
    return 0;
}


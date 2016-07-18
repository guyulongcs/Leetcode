
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>
#include <algorithm>

#include <cmath>

using namespace std;

class Solution {
    char op[3] = {'+', '-', '*'};
    int opCnt = 3;
    
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        
        int N=num.size();
        if(N == 0)
            return res;
        
        string cur;
        
        //dfs_op(num, 0, N-1, target, cur, res);
        
        dfs(num, target, res, N, 0, "", 0, 0);
        
        return res;
    }
    
    void dfs(string num, int target, vector<string> & res, int N, int s, string str, long long cur, long long diff) {
        if(s == N) {
            if(cur == target) {
                res.push_back(str);
            }
            return;
        }
        
        for(int i=1; i <= N-s; i++) {
            string curStr = num.substr(s, i);
            if(curStr.length() > 1 && curStr[0] == '0')
                break;
            long long curNum = (long long)atol(curStr.c_str());
            if(s == 0) {
                dfs(num, target, res, N, s+i, curStr, curNum, curNum);
            }
            else {
                dfs(num, target, res, N, s+i, str + "+" + curStr, cur+curNum, curNum);
                dfs(num, target, res, N, s+i, str + "-" + curStr, cur-curNum, -curNum);
                dfs(num, target, res, N, s+i, str + "*" + curStr, cur-diff+diff*curNum, diff * curNum);
                
            }
        }
    }
    
    void dfs_op(string num, int s, int e, int target, string cur, vector<string> & res ) {
        
        if(s > e) {
            int n = eval(cur);
            //cout << "cur:" << cur << ",num:" << n << endl;
            if(target == n) {
                res.push_back(cur);
            }
            return;
        }
        
        char ch = num[s];
        
        
        
        //add op
        if(cur != "") {
            for(int i=0; i < opCnt; i++) {
                cur.push_back(op[i]);
                cur.push_back(ch);
                dfs_op(num, s+1, e, target, cur, res);
                cur.pop_back();
                cur.pop_back();
            }
        }
        
        //not add op
        if(cur != "" && cur[cur.length()-1] == '0')
            return;
        
        cur.push_back(ch);
        dfs_op(num, s+1, e, target, cur, res);
        cur.pop_back();
        
    }
    
    void printVecStr(vector<string> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    int eval(string str) {
        int res = 0;
        stack<int> sNum;
        stack<char> sOp;
        
        int num=0;
        for(int i=0; i < str.length(); i++) {
            char ch = str[i];
            if(isOp(ch)) {
                sNum.push(num);
                num=0;
                
                if(ch == '*') {
                    sOp.push(ch);
                }
                else {
                    calStack(sNum, sOp);
                    sOp.push(ch);
                }
            }
            else {
                num = num * 10 + (ch-'0');
            }
        }
        sNum.push(num);
        
        calStack(sNum, sOp);
        
        if(sNum.size() > 0)
            res = sNum.top();
        return res;
    }
    
    void calStack(stack<int> & sNum, stack<char> & sOp) {
        if(sOp.empty() || sNum.size() < 2)
            return;
        
        while(!sOp.empty()) {
            if(sNum.size() < 2)
                break;
            char op = sOp.top();
            sOp.pop();
            int n1 = sNum.top();
            sNum.pop();
            int n2 = sNum.top();
            sNum.pop();
            int n = calNum(n2, n1, op);
            sNum.push(n);
        }
    }
    
    int calNum(int n1, int n2, char op) {
        int n=0;
        if(op == '+')
            n = n1 + n2;
        else if(op == '-') {
            n = n1 - n2;
        }
        else if(op == '*') {
            n = n1 * n2;
        }
        return n;
    }
    bool isOp(char ch) {
        return (ch == '+' || ch == '-' || ch == '*');
    }
};


int main() {
    Solution s= Solution();

    string num = "123";
    int target = 6;
    vector<string> res = s.addOperators(num, target);
    s.printVecStr(res);


    return 0;
}



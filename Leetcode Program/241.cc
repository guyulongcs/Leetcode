#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        //res = diffWaysToCompute_recur(input);
        res = diffWaysToCompute_dp(input);

        return res;
    }
    
    vector<int> diffWaysToCompute_recur(string input) {
        vector<int> v;
        int N = input.length();
        
        if(N == 0) {
            return v;
        }
        
        int num=0;
        
        for(int i=0; i < N; i++) {
            char ch = input[i];
            if(isdigit(ch)) {
                num = num * 10 + (ch-'0');
            }
            else {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                mergeLeftRight(left, right, ch, v);
            }
        }
        if(v.empty()) {
            v.push_back(num);
        }
        return v;
    }
    
    vector<int> diffWaysToCompute_dp(string input) {
        vector<int> v;
        int N = input.length();
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>()));
        
        if(N == 0) {
            return v;
        }
        
        diffWaysToCompute_dp_help(input, 0, N-1, dp, v);
        return v;
    }
    
    
    void diffWaysToCompute_dp_help(string& input, int start, int end, vector<vector<vector<int>>>& dp, vector<int>& v){
        int num=0;
    
        if(dp[start][end].size() > 0) {
            v = dp[start][end];
            return;
        }
        
        for(int i=start; i <= end; i++) {
            char ch = input[i];
            if(isdigit(ch)) {
                num = num * 10 + (ch-'0');
            }
            else {
                vector<int> left;
                vector<int> right;
                diffWaysToCompute_dp_help(input, start, i-1, dp, left);
                diffWaysToCompute_dp_help(input, i+1, end, dp, right);
                mergeLeftRight(left, right, ch, v);
            }
        }
        if(v.empty()) {
            v.push_back(num);
        }
        dp[start][end] = v;
    }

    void mergeLeftRight(vector<int> & left, vector<int> & right, char op, vector<int> & v) {
        for(int i=0; i < left.size(); i++) {
            for(int j=0; j < right.size(); j++) {
                int res = calOpNums(op, left[i], right[j]);
                v.push_back(res);
            }
        }
    }
    
    
    vector<int> diffWaysToCompute_Stack(string input) {
        vector<int> v;
        int N = input.length();
        
        stack<int> sNums;
        stack<char> sOp;
        
        if(N == 0) {
            return v;
        }
        
        int num=0;
        
        cal(input, 0, num, sNums, sOp, v);
        
        return v;
        
        
    }
    
    void cal(string & s, int i, int & num, stack<int> sNums, stack<char> sOp, vector<int> & v) {

        char ch = s[i];
        
//        cout << "cal: i:" << i << "\tch:" << ch << endl;
        if(i >= s.length()) {
            sNums.push(num);
            
//            cout << endl;
//            cout << "sNums:";
//            pringtStack(sNums);
//            cout << "sOp:";
//            pringtStackChar(sOp);
//
//            cout << "calNum:" << endl;
            
            calNum(sNums, sOp);
            
//            cout << "calNum end:" << endl;
//            cout << "top:" << sNums.top() << endl;
            
            if(!sNums.empty())
                v.push_back(sNums.top());
            return;
        }
        
        if(isOp(ch)) {
            sNums.push(num);
            
            for(int j= 0; j <= sOp.size(); j++) {
                stack<int> sNumsBack = sNums;
                stack<char> sOpBack = sOp;
                calNum(sNumsBack, sOpBack, j);
                sOpBack.push(ch);
                int numNew2 = 0;
                cal(s, i+1, numNew2, sNumsBack, sOpBack, v);
            }
        }
        else {
            num = num * 10 + (ch-'0');
            cal(s, i+1, num, sNums, sOp, v);
        }
        
    }
    
    void addOp(stack<int>& sNums, stack<char>& sOp, char ch) {
        if(!sOp.empty()) {
            calNum(sNums, sOp);
            sOp.push(ch);
        }
    }
    
   
    void pringtStack(stack<int> s) {
//        cout << endl << "stack:";
        while(!s.empty()) {
            cout << s.top() << "\t";
            s.pop();
        }
//        cout << endl;
    }
    
    void pringtStackChar(stack<char> s) {
//        cout << endl << "stack:";
        while(!s.empty()) {
            cout << s.top() << "\t";
            s.pop();
        }
        cout << endl;
    }
    
    
    void calNum(stack<int>& sNums, stack<char>& sOp, int cnt=-1) {
        int i=0;
        
        while(!sOp.empty()) {
            if(cnt >= 0 && i >= cnt) {
                break;
            }
            i++;
            
            if(sNums.size() < 2) {
                break;
            }
            
            char ch = sOp.top();
            
            //n1
            if(sNums.empty()) {
                break;
            }
            int n1 = sNums.top();
            sNums.pop();
            
            //n2
            if(sNums.empty()) {
                break;
            }
            int n2 = sNums.top();
            sNums.pop();
            
            //res
            int res = calOpNums(ch, n2, n1);
            sNums.push(res);
            
            sOp.pop();
            
            
        }
    }
    
    int calOpNums(char ch, int nBefore, int nAfter) {
        int res = 0;
        if(ch == '+') {
            res = nBefore + nAfter;
        }
        else if(ch == '-' ) {
            res = nBefore - nAfter;
        }
        else if(ch == '*') {
            res = nBefore * nAfter;
        }
        return res;
    }
    
    bool isOp(char ch) {
        return (ch == '+' || ch == '-' || ch == '*');
    }
};

int main() {
    Solution s;
    string str = "3-4*5+2";
    
    vector<int> res = s.diffWaysToCompute(str);
    for(int i=0; i < res.size(); i++) {
        cout <<res[i] << endl;
    }
  

    return 0;
}

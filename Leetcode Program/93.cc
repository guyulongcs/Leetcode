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

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int N = s.length();
        vector<string> cur;
        dfs(s, 0, N-1, cur, res);
        return res;
    }
    
    void dfs(string str, int s, int e, vector<string> & cur, vector<string> & res) {
        if(s > e) {
            if(isValidIp(cur)) {
                string curStr;
                curStr = getIpStrFromVec(cur);
                res.push_back(curStr);
            }
            return;
        }
        
        char ch = str[s];
        
        if(cur.size() > 4)
            return;
        
        int maxLen = 3;
        if(ch == '0') {
            maxLen = 1;
        }
        
        for(int l=1; l <= maxLen && s+l-1 <= e; l++) {
            string tmp = str.substr(s, l);
            //cout << "tmp:" << tmp << endl;
            int n = atoi(tmp.c_str());
            if(n >=0 && n <= 255) {
                cur.push_back(tmp);
                dfs(str, s+l, e, cur, res);
                cur.pop_back();
            }
        }
        
    }
    
    string getIpStrFromVec(vector<string> & v) {
        string res;
        for(int i=0; i < v.size(); i++) {
            if(res == "") {
                res = v[i];
            }
            else {
                res = res + "." + v[i];
            }
        }
        return res;
    }
    bool isValidIp(vector<string> & v) {
        bool flag = false;
        if(v.size() == 4) {
            flag = true;
        }
        return flag;
    }
    
    void printVecStr(vector<string> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
};


int main() {
    Solution s= Solution();

    string num = "010010";
   
    vector<string> res = s.restoreIpAddresses(num);
    s.printVecStr(res);
   
    
    return 0;
}



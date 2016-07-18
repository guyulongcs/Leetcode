#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        int N = path.length();
        string res;
        if(N == 0)
            return res;
        
        
        vector<string> v;
        splitStr(path, v);
        
    
        res = simplify(v);
        return res;
        
    }
    
    string simplify(vector<string> & v) {
        string res;
        int N = v.size();
        //cout << N << endl;
        if(N == 0)
            return res;
        
        stack<string> s;
        for(int i=0; i < N; i++) {
            string cur = v[i];
            if(cur == ".") {
                continue;
            }
            else if(cur == "..") {
                if(!s.empty()) {
                    s.pop();
                }
            }
            else {
                s.push(cur);
            }
        }
        
        if(s.empty()) {
            res = "/";
            return res;
        }
        
        while(!s.empty()) {
            string cur = s.top();
            s.pop();
            if(cur != "/")
                res = "/" + cur + res;
            else
                res = cur + res;
        }
        return res;
        
    }
    
    void splitStr(string str, vector<string> & v, char chSplit = '/') {
        int N = str.length();
        string cur;
        int cnt=0;
        for(int i=0; i < N; i++) {
            char ch = str[i];
            if(ch == chSplit) {
                cnt++;
                if(cur != "") {
                    v.push_back(cur);
                    cur = "";
                }
            }
            else {
                cur.push_back(ch);
            }
        }
        if(cur != "") {
            v.push_back(cur);
        }
        if(v.empty() && cnt > 0) {
            v.push_back("/");
        }
    }
    
    
    
};


int main() {


    Solution s;
    string str = "/..";
    
    string res = s.simplifyPath(str);

    cout << res << endl;


    return 0;
}


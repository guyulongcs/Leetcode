#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isValidSerialization(string preorder) {
        bool flag = false;
        flag = isValidSerializationStack(preorder);
        return flag;
    }
    
    bool isValidSerializationStack(string preorder) {
        int N = preorder.length();
        if(N == 0)
            return false;
        stack<string> s;
        
        string cur;
        bool flagNum = false;
        for(int i=0; i < N; i++) {
            char ch = preorder[i];
            
            if(ch == ',') {
                s.push(cur);
                addCur(cur, s, flagNum);
            }
            else {
                cur.push_back(ch);
            }
        }
        if(cur.length() > 0) {
            s.push(cur);
            addCur(cur, s, flagNum);
        }
        
        bool flag =  (s.size() == 1 && s.top() == "#");
        return flag;
    }
    
    void addCur(string & cur, stack<string> & s, bool & flagNum) {
//        cout << "cur:" << cur << endl;

        if(cur == "#") {
            updateStack(s);
        }
        else {
            flagNum = true;
        }
        cur = "";

    }
    
    void updateStack(stack<string> & s) {
//        cout << "s.size():" << s.size() << endl;
        bool flagUpdate = true;
        while(s.size() >= 3 && flagUpdate) {
            string s1 = s.top();
//            cout << "s1:" << s1 << endl;
            flagUpdate = false;
            if(s1 == "#") {
                s.pop();
                string s2 = s.top();
                if(s2 == "#") {
                    s.pop();
                    string s3 = s.top();
                    if(s3 != "#") {
                        s.pop();
                        flagUpdate = true;
                        s.push("#");
                    }
                    else {
                        s.push("#");
                        s.push("#");
                    }
                    
                }
                else {
                    s.push("#");
                }
            }
        }
    }
    bool isValidSerializationStr(string & preorder) {
         bool flag = false;
        
        string str;
        
        vector<string> v;
        splitString(preorder, ",", v);
        //        printVecString(v);
        
        vecStringNormToString(v, str);
        
        unordered_map<string, bool> dp;
        
        flag = isValidSerializationStrHelp(str, 0, str.length()-1, dp);
        
        return flag;
    }
    
    bool isValidSerializationStrHelp(string & str, int s, int e, unordered_map<string, bool> & dp) {
//        cout << "isValidSerializationStrHelp" << endl;
        bool flag = false;
        
        if(s > e) {
            return false;
        }
        
        string strSub = str.substr(s, e-s+1);
//        cout << "strSub:" << strSub << endl;
        
        if(dp.find(strSub) != dp.end()) {
            return dp[strSub];
        }
        
        if(s == e) {
            flag = (str[s] == '0');
            return flag;
        }
        else {
            if(str[s] == '0') {
                return false;
            }
            if(e-s+1 % 2 == 0) {
                flag = false;
            
            }
            else {
                for(int k=1; k <= e-s-1; k+=2) {
                    bool flagLeft = false;
                    bool flagRight = false;
                    flagLeft = isValidSerializationStrHelp(str, s+1, s+k, dp);
                    if(flagLeft) {
                        flagRight = isValidSerializationStrHelp(str, s+k+1, e, dp);
                    }
                    flag = (flagLeft && flagRight);
                    if(flag) {
                        break;
                    }
                }
            }
        }
        dp[strSub] = flag;
        
        //cout << strSub << "\t" << flag << endl;
        return flag;
    }
    
    void vecStringNormToString(vector<string> & v, string & str) {
        for(int i=0; i < v.size(); i++) {
            string cur;
            if(v[i] == "#") {
                cur = "0";
            }
            else {
                cur = "1";
            }
            str += cur;
        }
    }
    
    void printVecString(vector<string> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    void splitString(string str, string splitStr, vector<string> & v) {
        int start=0;
        string s = str;
        size_t pos_start = s.find_first_not_of(splitStr);
        size_t pos;
        string cur;
        while(true) {
            pos =  s.find(splitStr, pos_start);
            if(pos != string::npos) {
                cur = s.substr(pos_start, pos-pos_start);
                v.push_back(cur);
                pos_start=pos+1;
            }
            else {
                cur = s.substr(pos_start);
                break;
            }
        }
        if(cur.length() > 0) {
            v.push_back(cur);
        }
    }
    
    
};


int main() {

    Solution s;
    vector<int> v({0,1,0,2,1,0,1,3,2,1,2,1});
    
    
    string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    
    bool res = s.isValidSerialization(str);
    cout << res << endl;

    return 0;
}



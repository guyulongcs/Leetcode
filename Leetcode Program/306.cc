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
    bool isAdditiveNumber(string num) {
        int N=num.length();
        bool flag = false;
        string str;
        vector<string> v;
        dfs(num, 0, N-1, flag, v, str);
        return flag;
    }
    
    
    
    void dfs(string num, int s, int e, bool & flag, vector<string> & v, string str) {
        if(s > e) {
            if(str != "") {
                v.push_back(str);
            }
            if(isValid(v)) {
                flag = true;
            }
            return;
        }
        
        if(flag) {
            return;
        }
        
        char ch = num[s];
        
        string strNew;
        strNew.push_back(ch);
        if(str != "") {
            v.push_back(str);
        }
        if(v.size() < 3 || isValid(v)) {
            dfs(num, s+1, e, flag, v, strNew);
        }
        if(str != "") {
            v.pop_back();
        }
        
        //add to pre
        if(str != "" && str != "0")
        {
            str.push_back(ch);
            //cout << "str:" << str << endl;
            vector<string> vOld = v;
            dfs(num, s+1, e, flag, v, str);
            v = vOld;
        }
    }
    
    bool isValid(vector<string> & v) {
        bool flag = false;
        int N = (int)v.size();
        if(N >= 3) {
            string s1 = v[N-3];
            string s2 = v[N-2];
            string s3 = v[N-1];
            int n1 = atoi(s1.c_str());
            int n2 = atoi(s2.c_str());
            int n3 = atoi(s3.c_str());
            if(n1 + n2 == n3) {
                flag = true;
            }
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

    string str = "211738";
    bool flag = s.isAdditiveNumber(str);
    cout << flag << endl;
    
    return 0;
}



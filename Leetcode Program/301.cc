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
    vector<string> removeInvalidParentheses(string str) {
        
        int maxPairCnt = getMaxPairCnt(str);
        //cout << "maxPairCnt:" << maxPairCnt << endl;
        vector<string> v;
        
        getAllValid(str, maxPairCnt, v);
        
        removeDuplicateVecStr(v);
        
        return v;
    }
    
    void getAllValid(string & str, int maxPairCnt, vector<string> & v) {
        stack<char> st;
        string res;
        int pairCnt=0;
        getAllValidHelp(str, pairCnt, maxPairCnt, v, 0, st, res);
        
    }
    
    void getAllValidHelp(string & str, int pairCnt, int maxPairCnt, vector<string> & v, int begin, stack<char> st, string res) {
        
        int i = begin;
        
        if(pairCnt > maxPairCnt)
            return;
        
        if(str.length()-begin < maxPairCnt - pairCnt)
            return;
        
        for(i=begin; i < str.length(); i++) {
            char ch = str[i];
            if(ch == '(') {
                st.push(ch);
                res.push_back('(');
                //add
                if(maxPairCnt >= pairCnt) {
                    getAllValidHelp(str, pairCnt, maxPairCnt, v, i+1, st, res);
                }
                
                //not add
                st.pop();
                res.pop_back();
                getAllValidHelp(str, pairCnt, maxPairCnt, v, i+1, st, res);
                return;
            }
            else if(ch == ')') {
                if(!st.empty()) {
                    //add
                    st.pop();
                    res.push_back(')');
                    pairCnt++;
                    getAllValidHelp(str, pairCnt, maxPairCnt, v, i+1, st, res);
                    
                    //not add
                    st.push('(');
                    res.pop_back();
                    pairCnt--;
                    getAllValidHelp(str, pairCnt, maxPairCnt, v, i+1, st, res);
                    
                    return;
                }
            }
            else {
                res.push_back(ch);
            }
        }
        if(i == str.length() && pairCnt == maxPairCnt && st.empty()) {
            v.push_back(res);
//            if(!st.empty()) {
//                v.push_back(res);
//            }
//            else {
//                v.push_back("");
//            }
        }
    }
    
    int getMaxPairCnt(string & str) {
        stack<char> st;
        string res;
        int removeCnt = 0;
        int maxPairCnt=0;
        for(int i=0; i < str.length(); i++) {
            char ch = str[i];
            if(ch == '(') {
                st.push(ch);
                res += "(";
            }
            else if(ch == ')') {
                if(!st.empty()) {
                    res += ")";
                    st.pop();
                    maxPairCnt++;
                }
                else {
                    removeCnt++;
                }
            }
            else {
                res.push_back(ch);
            }
        }
        
        return maxPairCnt;
    }
    
    void removeDuplicateVecStr(vector<string> & v) {
        unordered_set<string> set;
        for(int i=0; i < v.size(); i++) {
            set.insert(v[i]);
        }
        v.clear();
        for(auto it=set.begin(); it != set.end(); it++) {
            v.push_back(*it);
        }
    }
    
    
};



int main() {

    Solution s;
    vector<int> v({0,1,0,2,1,0,1,3,2,1,2,1});
    
    
    string str = "n";
    
    vector<string> res = s.removeInvalidParentheses(str);
    for(int i=0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}



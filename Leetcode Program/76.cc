#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if(s == "" || t == "") {
            return res;
        }
        
        int b=0;
        int e=-1;
        
        int ls = (int)s.length();
        
        map<char, int> tMap = getStrCharMap(t);
        int minLen = INT32_MAX;
        int resBegin = 0;
        set<char> curCharSet;
        map<char, int> curMap;
        bool flag = false;
        bool flagHasResult = false;
        
        while(true){
            flag = expand(s, t, ls, b, e, tMap, curMap, curCharSet);
            if(!flag)
                break;
            else {
                flagHasResult = true;
            }
            shrinkage(s, t, ls, b, e, tMap, curMap, minLen, resBegin);
            forward(s, ls, b, e, tMap, curMap, curCharSet);
        }
        if(flagHasResult)
            res = s.substr(resBegin, minLen);
        return res;
    }
    
    map<char, int> getStrCharMap(string t) {
        map<char, int> tMap;
        for(int i=0; i < t.length(); i ++) {
            tMap[t[i]]++;
        }
        return tMap;
    }
    
    bool expand(string & s, string & t, int ls, int & b, int & e, map<char, int> & tMap, map<char, int> & curMap,  set<char> & curCharSet) {
        if(b >= ls) {
            return false;
        }
       
        int curCnt=0;
       
        while(e < ls) {
             ++e;
            char ch = s[e];
            if(tMap.count(ch) > 0) {
                curMap[ch]++;
                if(curMap[ch] >= tMap[ch]) {
                    curCharSet.insert(ch);
                    if(curCharSet.size() == tMap.size()) {
                        break;
                    }
                }
                curCnt++;
            }
            
            
        }
        bool flag =  (e < ls && curCharSet.size() == tMap.size());
        return flag;
    }
    
    void shrinkage(string & s, string & t, int ls, int & b, int & e, map<char, int> & tMap, map<char, int> & curMap, int & minLen, int & resBegin) {
       
        while(b <= e) {
            int len = e-b+1;
            if(len < minLen) {
                minLen = len;
                resBegin = b;
            }
            if(b == ls) {
                break;
            }
            char ch = s[b];
            if(tMap.count(ch) > 0) {
                if(curMap[ch] <= tMap[ch]) {
                    break;
                }
                else {
                    curMap[ch]--;
                    b++;
                }
            }
            else {
                b++;
            }
        }

    }
    
    void forward(string & s, int ls, int & b, int & e, map<char, int> & tMap, map<char, int> & curMap, set<char> & curCharSet) {
        if(b >= ls) {
            return;
        }
        char ch = s[b];
        if(tMap.count(ch) > 0) {
            curMap[ch]--;
            if(curMap[ch] < tMap[ch]) {
                curCharSet.erase(ch);
            }

            if(curMap[ch] <= 0) {
                curMap.erase(ch);
            }
           
        }
        b++;
    }
};


int main() {
    Solution sol = Solution();
    
    string s;
    string t;
    string res;
    
    s = "ADOBECODEBANC";
    t = "ABC";
    res = sol.minWindow(s, t);
    cout << res << endl;
    
    s = "aa";
    t = "aa";
    res = sol.minWindow(s, t);
    cout << res << endl;
    
    return 0;
}

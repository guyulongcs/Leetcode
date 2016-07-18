#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool flag = false;
        
        int l1 = (int)s.length();
        int l2 = (int)p.length();
        
        
        flag = isMatchFunc(s, p, l1,l2, 0, 0);
        
        return flag;
    }
    
    bool isMatchFunc(string & s, string & p, int l1, int l2, int i, int j) {

        if(j >= l2) {
            return i >= l1;
        }
        
        //next is *
        if(j+1 < l2 && p[j+1] == '*') {
            while(s[i] == p[j] || (p[j] == '.' && i < l1)) {
                if(isMatchFunc(s, p, l1, l2, i++, j+2)) {
                    return true;
                }
            }
            return isMatchFunc(s, p, l1, l2, i, j+2);
        }
        //next is not *
        else {
            if(i < l1)
                return ((s[i] == p[j]) || (p[j] == '.')) && isMatchFunc(s, p, l1, l2, i+1, j+1);
            else
                return false;
        }
    }
    
    bool isMatchEmpty(string & s, int l, int i) {
//        cout << "isMatchEmpty:" << i << endl;
        bool flag = false;
        while(s[i] == '*') {
            i++;
        }
        int j;
        for(j=i; j < l; j+=2) {
            if(j+1 >= l || s[j+1] != '*') {
                flag = false;
                break;
            }
        }
        if(j == l) {
            flag = true;
        }
        //cout << flag << endl;
        return flag;
    }
    
};



int main() {
    Solution sol = Solution();

    //s.testPQ();
    //return 0;

    string s;
    string p;
    bool res;
    
    s = "ab";
    p = ".*..";
    res = sol.isMatch(s, p);
    cout << res << endl;



    return 0;
}



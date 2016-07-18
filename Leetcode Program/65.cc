#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isNumber(string s) {

        bool flag = false;
        int N = s.length();
        if(N == 0)
            return false;
        
        int state = 1;
        
        const int ERR = 10;
        for(int i=0; state != ERR && i < N; i++) {
            char ch = s[i];
            if(state == 1) {
                if(isBlank(ch)) {
                    
                }
                else if(isCharPosNeg(ch)) {
                    state = 2;
                }
                else if(isdigit(ch)) {
                    state = 5;
                }
                else if(isCharPoint(ch)) {
                    state = 3;
                }
                else {
                    state = ERR;
                }
            }
            else if(state == 2) {
                if(isCharPoint(ch)) {
                    state = 3;
                }
                else if(isdigit(ch)) {
                    state = 5;
                }
                else {
                    state = ERR;
                }
            }
            else if(state == 3) {
                if(isdigit(ch)) {
                    state = 4;
                }
                else {
                    state = ERR;
                }
            }
            else if(state == 4) {
                if(isdigit(ch)) {
                    
                }
                else if(ch == 'e') {
                    state = 6;
                }
                else if(ch == ' ') {
                    state = 9;
                }

                else {
                    state = ERR;
                }
            }
            else if(state == 5) {
                if(isdigit(ch)) {
                    
                }
                else if(isCharPoint(ch)) {
                    state = 4;
                }
                else if(ch == ' ') {
                    state = 9;
                }
                else if(ch == 'e') {
                    state = 6;
                }
                else {
                    state = ERR;
                }
            }
            else if(state == 6) {
                if(isdigit(ch)) {
                    state = 8;
                }
                else if(isCharPosNeg(ch)) {
                    state = 7;
                }
                else {
                    state = ERR;
                }
            }
            else if(state == 7) {
                if(isdigit(ch)) {
                    state = 8;
                }
                else {
                    state = ERR;
                }
            }
            else if(state == 8) {
                if(isdigit(ch)) {
                
                }
                else if(ch == ' ') {
                    state = 9;
                }
                else {
                    state = ERR;
                }
            }
            else if(state == 9) {
                if(ch != ' ') {
                    state = ERR;
                }
            }
        }
       
        if(state == 4 || state == 5 || state == 8 || state == 9) {
            flag = true;
        }
        return flag;
    }
    
    bool isNumber1(string s) {
        
        bool flag = false;
        int N = s.length();
        if(N == 0)
            return false;
        
        int index=0;
        while(index < N && isBlank(s[index])) {
            index++;
        }
        
        bool flagEBeforePosNeg = false;
        bool flagEAfterPosNeg = false;
        if(index < N && isCharPosNeg(s[index])) {
            flagEBeforePosNeg = true;
            index++;
        }
        
        bool flagEBefore = false;
        bool flagEAfter = false;
        bool flagE = false;
        
        bool flagBlank = false;
        
        
        
        
        int pointCnt=0;
        //int eCnt = 0;
        for(;index < N;index++) {
            char ch = s[index];
            if(!isVliadChar(ch)) {
                flag = false;
                break;
            }
            if(isBlank(ch)) {
                flagBlank = true;
            }
            
            if(flagBlank && !isBlank(ch)) {
                flag = false;
                break;
            }
            
            
            if(isCharPoint(ch)) {
                pointCnt++;
                if(pointCnt > 1) {
                    break;
                }
                if(flagE) {
                    break;
                }
            }
            if(ch == 'e') {
                pointCnt = 0;
                //eCnt++;
                if(flagE == true) {
                    break;
                }
                flagE = true;
            }
            
            if(isCharPosNeg(ch)) {
                if(index < 1 || s[index-1] != 'e') {
                    flag = false;
                    break;
                }
            }

            if(isdigit(ch)) {
                if(!flagE) {
                    flagEBefore = true;
                }
                else {
                    flagEAfter = true;
                }
            }
        }
        
        if(index == N) {
            flag = true;
            if(flagE) {
                if(!flagEBefore || !flagEAfter)
                    flag = false;
            }
            else {
                if(!flagEBefore || (flagEBefore && flagEAfter)) {
                    flag = false;
                }
                
            }
        }
        return flag;
    }
    
    bool isBlank(char ch) {
        return ch == ' ';
    }
    
    bool isCharPosNeg(char ch) {
        bool flag = ( ch=='+' || ch == '-');
        return flag;
    }
    
    bool isVliadChar(char ch) {
        bool flag = isCharPosNeg(ch) || isdigit(ch) || ch == '.' || ch == 'e' || ch == ' ';
        return flag;
    }
    
    bool isCharPoint(char ch) {
        return ch=='.';
    }
};

int main() {
    Solution s;
    vector<string> v({
        "0", "0.1", "-0.1", "2e10", "2e-10", "+2e+10", "-10",
        "abc", "-0. 1", "1 a", ".", "e", "1 ", "1. ", "1. 2", "6+1", "6e6.5"
    });
    for(int i=0; i < v.size(); i++) {
        string str = v[i];
        bool res1=s.isNumber(str);
        bool res2 =s.isNumber1(str);
        bool res = ( res1== res2);
        cout << "compare " << str << "\t\t" << res1 << "\t\t" << res2 << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;



class Solution {
public:
    int calculate(string s) {
        stack<long long> nums;
        stack<char> opes;
        
        int lc = 0;
        bool fValid = true;
        
        bool fNum = false;
        long long cNum = 0;
        for(int i=0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == ' ') {
                continue;
            }
            else if(isdigit(ch)) {
                int digit = ch - '0';
                cNum = cNum * 10 + digit;
                
                if(i == s.length()-1 || !isdigit(s[i+1])) {
                    nums.push(cNum);
                    cNum = 0;
                }
                
            }
            else if(isOp(ch)) {
                if(!opes.empty()) {
                    char opOld = opes.top();
                    if(!isHighOrder(ch, opOld)) {
                        calStack(nums, opes, ch);
                    }
                }
                opes.push(ch);
            }
            else {
                fValid = false;
                break;
            }
            //printInfo(ch, nums, opes);
        }
        
        calStack(nums, opes, '0');
        int res = 0;
        if(fValid){
            res = nums.top();
        }
        
        return res;
    }
    
    bool isOp(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }
    
    bool isHighOrder(char ch1, char ch2) {
        bool flag = false;
        if((ch1 == '*' || ch1 == '/') && (ch2 == '+' || ch2 == '-')) {
            flag = true;
        }
        return flag;
    }
    void printInfo(char ch, stack<long long > nums, stack<char> opes) {
        cout << endl << "info..." << endl;
        cout << "ch:" << ch << endl;
        
        cout<< "nums" << endl;
        while(nums.size() > 0) {
            cout << nums.top() << "\t";
            nums.pop();
        }
        cout << endl;
        
        cout<< "opes" << endl;
        while(opes.size() > 0) {
            cout << opes.top() << "\t";
            opes.pop();
        }
        cout << endl;
        
        
    }
    
    
    bool calStack(stack<long long >& nums, stack<char>& opes, char ch='0') {
        
        bool fValid = true;
        if(nums.size() == 1 && opes.size() == 0) {
            return fValid;
        }
        //        if(nums.size() < 2 || opes.size() < 1) {
        //            fValid = false;
        //            return fValid;
        //        }
        while(opes.size() > 0) {
            char ope = opes.top();
            
            if(isHighOrder(ch, ope))
                break;
            
            opes.pop();
            //cout << "ope:" << ope << endl;
            
            if(nums.size() < 2) {
                fValid = false;
                return fValid;
            }
            long long num1 = nums.top();
            nums.pop();
            long long num2 = nums.top();
            nums.pop();
            
            
            long long res = 0;
            if(ope == '+') {
                res = num2 + num1;
            }
            else if(ope == '-'){
                res = num2 - num1;
            }
            else if(ope == '*'){
                res = num2 * num1;
            }
            else if(ope == '/'){
                res = num2 / num1;
            }
            
            nums.push(res);
            
//            if(ch != '0') {
//                break;
//            }
            
        }
        return fValid;
        
    }
    
};


int main() {


    Solution s;
    int a=2;
    int b=3;

    string str = "1*2-3/4+5*6-7*8+9/10";
    int c= s.calculate(str);
    cout << c <<endl;
    

    

    return 0;
}


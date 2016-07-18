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
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0)
            return "0";
        
        bool flagNeg = ((numerator < 0) ^ (denominator < 0));
        
        
        long long a1 = abs((long long)numerator);
        long long b1 = abs((long long)denominator);
        
        long long e = a1 / b1;
        long long a=a1 % b1;
        string res;
        string s1 = to_string(e);
        string s2;
        if( a > 0) {
            s2 = divide(a, b1);
        }
        res = s1 + s2;
        
        if(flagNeg) {
            if(res != "0")
                res = "-" + res;
        }
        return res;
    }
    
    
    
    string divide(long long a, long long b) {
        string res;
        
        long long d;
        long long e;
        long long f = a;
        
        vector<int> v;
        vector<int> vm;
        int i = 0;
        bool flagRepeat = false;
        int index=0;
        vm.push_back(a);
        while(f != 0) {
            d = f * 10;
            e = d/b;
            f = d%b;
            
            v.push_back(e);
            index = findVec(vm, f);
            if(index == -1) {
                vm.push_back(f);
            }
            else {
                break;
            }
            i++;
        }
    
        if(index == -1) {
            for(i=0; i < v.size(); i++) {
                res = res + to_string(v[i]);
            }
        }
        else {
            for(i=0; i < v.size(); i++) {
                if(i == index) {
                    res = res + "(";
                }
                res = res + to_string(v[i]);
            }
            res = res + ")";
        }
        
        res = "." + res;
        return res;
    }
    
    int findVec(vector<int> & v, int num) {
        int index=-1;
        for(int i=0; i < v.size(); i++) {
            if(v[i] == num) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    Solution s;
    int a = 7;
    int b = -12;
    string str = s.fractionToDecimal(a, b);
    cout << str << endl;
    

    return 0;
}

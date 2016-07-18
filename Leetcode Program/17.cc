#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


 

class Solution {
private:
    unordered_map<char, string> map;
public:
    
    Solution() {
        map =unordered_map<char, string>();
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
    }
    
    string char2string(char ch) {
        char a[2];
        a[0] = ch;
        a[1] = '\0';
        string s(a);
        return s;
    }
    
    vector<string> letter2VS(char ch) {
        string str = map[ch];
        vector<string> res;
        for(int i=0; i < str.length(); i++) {
            ch = str[i];
            string s = char2string(ch);
            res.push_back(s);
        }
        return res;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int N = digits.size();
        if(N==0)
            return res;
        if(N==1) {
            res = letter2VS(digits[0]);
            return res;
        }
            
        string subStr =digits.substr(0, N-1);
//        cout << subStr << endl;
        vector<string> preRes = letterCombinations(subStr);
        vector<string> curRes = letter2VS(digits[N-1]);
//        printVS(preRes);
        for(int i=0; i < preRes.size(); i++) {
            for(int j=0; j < curRes.size(); j++) {
                string pre = preRes[i];
                string cur = curRes[j];
                string str = pre+cur;
                res.push_back(str);
            }
        }
        return res;
    }
    
    void printVS(vector<string> v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    }
    
};


int main() {

    Solution s;
    
    vector<string> res = s.letterCombinations("23");
    s.printVS(res);
    
    return 0;
}


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
private:
    vector<string> mw1 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> mw21 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> mw22 = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    unordered_map<int, string> mq;
    
    
public:
    Solution() {
        mq[0] = "";
        mq[2] = "Hundred";
        mq[3] = "Thousand";
        mq[6] = "Million";
        mq[9] = "Billion";
    }
    string numberToWords(int num) {
        string res;
        if(num < 10) {
            res = mw1[num];
            return res;
        }
        else if(num < 20) {
            res = mw21[num-10];
            return res;
        }
        else if(num < 100) {
            int d1 = num % 10;
            int d2 = num / 10;
           
            string s2 = mw22[d2];
            string res = s2;
            if(d1 != 0) {
                string s1 = numberToWords(d1);
                res += " " + s1;
            }
            return res;
        }
        else if(num < 1000){
            int d3 = num / 100;
            int d12 = num % 100;
            string s3 = numberToWords(d3) + " " + mq[2];
            string res = s3;
            if(d12 > 0) {
                string s12 = numberToWords(d12);
                res += " " + s12;
            }
            return res;
        }
        else {
            vector<int> v;
            
            while(num) {
                int n = num % 1000;
                num = num / 1000;
                v.push_back(n);
            }
            
            int N = v.size();
            for(int i=N-1; i >=0; i--) {
                int base = 3*i;
                int n = v[i];
                if(n == 0) {
                    continue;
                }
                string curNum = numberToWords(n);
                string curBase = mq[base];
                string cur = curNum;
                if(curBase != "")
                    cur += " " + curBase;
                if(res != "") {
                    res += " ";
                }
                res += cur;
            }
            return res;
        }
    }
    
};


int main() {


    Solution s;
    string str = "/..";
    
    int n;
    string res;
//    for(n=0; n <= 100; n++) {
//        res = s.numberToWords(n);
//        cout << n << "\t" << res << endl;
//
//    }
    
    n=1234567891;
    res = s.numberToWords(n);
    cout << n << "\t" << res << endl;

    return 0;
}


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        
        int res = 0;
        
        int N = s.length();
        for(int i=0; i < N; i++) {
            bool flag = false;
            
            int cur = romanCharToInt(s[i]);
            int tmp = cur;
            if(i < N-1){
                int next = romanCharToInt(s[i+1]);
                if(cur < next) {
                    tmp = 0 - cur;
    
                }
            }
            res += tmp;
        }
        
        return res;
    }
          
    int romanCharToInt(char ch) {
        int res = 0;
        int a[1000];
        a['I'] = 1;
        a['V'] = 5;
        a['X'] = 10;
        a['L'] = 50;
        a['C'] = 100;
        a['D'] = 500;
        a['M'] = 1000;
        return a[ch];
    }
    
};

int main() {
    Solution s = Solution();
    string str="DCXXI";
    int n = s.romanToInt(str);
    cout << n << endl;
    
}


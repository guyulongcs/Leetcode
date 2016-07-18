#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        
        string s="1";
        for(int i=2; i <= n; i++) {
            s = nextStr(s);
        }
        return s;
    }
    
    string nextStr(string s) {
        string res;
    
        
        int N = s.length();
        int pre=-1;
        int cnt = 0;
        for(int i =0 ; i < N; i++) {
            int num = s[i] - '0';
            if(num == pre) {
                cnt++;
            }
            else{
                if(pre != -1) {
                    addStr(res, cnt, pre);
                }
                pre = num;
                cnt = 1;
                
            }
        }
        addStr(res, cnt, pre);
        
        return res;
    }
    
    void addStr(string & res, int cnt, int pre) {
        if(cnt == 0)
            return;
        string str = to_string(cnt) + to_string(pre);
        res += str;
    }
    
    vector<int> getBits(int n) {
        vector<int> v;
        while(true) {
            v.push_back(n%10);
            n=n/10;
            if(n==0) {
                break;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};


int main() {

    Solution s;
  
    string res = s.countAndSay(5);
    
    cout << res << endl;

    return 0;
}


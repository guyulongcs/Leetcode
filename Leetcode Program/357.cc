nclude <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res=0;
        if(n == 0)
            return 1;
        for(int i=1; i <=n; i++) {
            int cnt = 0;
            countWithUniqueDigits(i, cnt);
            //cout << i << "\t" << cnt << endl;
            res += cnt;
        }
        return res;
    }
    
    void countWithUniqueDigits(int len, int & cnt) {
        vector<bool> v(10, false);
        dfs(1, len, cnt, v);
    }
    
    void dfs(int s, int len, int & cnt, vector<bool> & v) {
        if(s > len) {
            cnt++;
            return;
        }
        
        for(int i=0; i <= 9; i++) {
            if(s == 1 && i==0 && len > 1) {
                continue;
            }
            if(v[i])
                continue;
            v[i] = true;
            dfs(s+1, len, cnt, v);
            v[i] = false;
        }
    }
    
};


int main() {
    Solution sol;
    int flag = sol.countNumbersWithUniqueDigits(2);
    cout << flag << endl;
   
    
    return 0;
}



#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;




class Solution {
    int M = 1337;
public:
    int superPow(int a, vector<int> & b) {
        int res=1;
        
        int N = (int)b.size();
        
        if(N == 0) {
            return 1;
        }
        
        a = a % M;
        
        int num = b.back();
        int cur = superPowerNum(a, num);
        b.pop_back();
        int pre = superPowerNum(superPow(a, b), 10);
        res = (pre * cur ) % M;
        
        return res;
    }
    
    int superPowerNum(int a, int b) {
        int res = 1;
        if(b == 0) {
            return 1;
        }
        
        int num = a;
        for(int i=0; i < b; i++) {
            res = (res * num ) % M;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    int a;
    vector<int> b;
    int res;
    
    a = 2;
    b = vector<int>({3});

    
    res = sol.superPow(a, b);
    cout << res << endl;
    
    return 0;
}


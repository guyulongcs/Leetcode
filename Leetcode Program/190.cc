#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<bool> v(32, false);
        const int Int_Bit_Max=32;
        int i = 0;
        while(n) {
            bool b = n & 1;
            v[i] = b;
            n = n >> 1;
            i++;
        }
        
//        printVec(v);
        
        uint32_t res=0;
        for(int i=0; i < Int_Bit_Max; i++) {
            res = (res << 1) + (int)v[i];
        }
        return res;
    }
    
    void printVec(vector<bool> v) {
        for(int i=0; i < v.size(); i++) {
            cout << int(v[i]);
        }
        cout << endl;
    }

};



int main() {
    Solution s= Solution();
    uint32_t res = s.reverseBits(43261596);
    cout << res << endl;
    return 0;
}



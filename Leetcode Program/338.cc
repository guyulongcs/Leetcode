#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        for (int i=0; i <= num; i++) {
            v.push_back(countBit(i));
        }
        return v;
    }
    
    int countBit(int n) {
        int count=0;
        while(n > 0) {
            n = n & (n-1);
            count++;
        }
        return count;
    }
 };

int main() {
    //assert(0);
    Solution s;
    int m =5;
    vector<int> v = s.countBits(m);
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    
}


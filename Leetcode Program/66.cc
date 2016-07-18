#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int num = 0;
        int c= 0;
        
        int rl = n;
        vector<int> v;
        int i=0;
        for(i=n-1; i>=0; i--) {
            
            num = digits[i] + c;
            if(i == n-1) {
                num += 1;
            }
            c = num / 10;
            num = num % 10;
//            cout << num << endl;
            v.push_back(num);
        }
        if(c > 0) {
            v.push_back(c);
            rl++;
        }
        
        vector<int> r(rl, 0);
        for(int i=rl-1; i >= 0; i--) {
            r[i] = v[rl-i-1];
        }
        return r;
    }
};

int main() {
    
    
    Solution s;
    
    int a[] = {0};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    
    //cout << v[0] << endl;
    
    int res=0;
    
    

    vector<int> v2 = s.plusOne(v);
    for(int i=0; i < v2.size(); i++) {
        cout << v2[i];
    }
    
    cout << endl;

    
    return 0;
}


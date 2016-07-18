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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int k = primes.size();
        vector<int> p(k, 1);
        vector<int> index(k, 0);
        
        if(n==1)
            return 1;
        
        vector<int> u(n+1, 0);
        
        int minV = 1;
        
        u[1] = 1;
        for(int i=1; i <= n; i++) {
            minV = minVec(p);
            u[i] = minV;
            for(int j=0; j < k; j++) {
                if(p[j] == minV) {
                    ++index[j];
                    p[j] = primes[j] * u[index[j]];
                }
            }
            
        }
        
        return minV;
    }
    
    int minVec(vector<int> p) {
        int minValue = INT32_MAX;
        for(int i=0; i<p.size(); i++) {
            minValue = min(minValue, p[i]);
        }
        return minValue;
    }
};

int main() {
    
    
    Solution s;
    
    int a[] = {2, 7, 13, 19};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    
    int res=0;
    
    for(int i=1; i <= 12; i++) {
        res =s.nthSuperUglyNumber(i, v);
        cout <<i << "\t"<< res << endl;
    }

    
    return 0;
}


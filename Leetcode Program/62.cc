#include <iostream>
//#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <=0 || n <= 0)
            return 0;
        
        vector<int> v(n, 1);
        for(int i=1; i < m; i++) {
            for(int j=1; j < n; j++) {
                v[j] = v[j-1] + v[j];
            }
        }
        return v[n-1];
    }
};

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    
    Solution s;
    
    
    int res = 0;
    res = s.uniquePaths(2,3);
    cout << res << endl;
    return 0;
}

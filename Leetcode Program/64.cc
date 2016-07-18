#include <iostream>
//#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v(n, INT32_MAX);
        
        v[0] = 0;
        for(int i=0; i < m; i++) {
            v[0] += grid[i][0];
            for(int j=1; j < n; j++) {
                int add = min(v[j-1], v[j]);
                v[j] = add + grid[i][j];
            }
        }
        return v[n-1];
    }
};

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    
    int m=3;
    int n=3;
    int aa[][3] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    
    Solution s;
    
    
    int res = 0;
    res = s.minPathSum(vv);
    cout << res << endl;
    return 0;
}

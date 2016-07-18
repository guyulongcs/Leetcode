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
    
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        if(obstacleGrid.size()== 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> v(n, 0);
        v[0]=1;
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                if(obstacleGrid[i][j] == 1)
                    v[j]=0;
                else {
                    if(j > 0)
                        v[j] = v[j-1] + v[j];
                }
            }
        }
        return v[n-1];
    }
    
};

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    Solution s;


    int m=3;
    int n=3;
    int aa[][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    int res = 0;
    res = s.uniquePathsWithObstacles(vv);
    cout << res << endl;
    return 0;
}

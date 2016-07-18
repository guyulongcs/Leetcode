#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector< vector<int> >& a) {
        if(a.size() == 0 || a[0].size() == 0)
            return 0;
        int m = a.size();
        int n = a[m-1].size();

        vector<int> s(n+1, 0);
       
        for(int level = n-1; level >= 0; level--){
            for(int j=0; j <= level; j++) {
                int minValue = min(s[j], s[j+1]);
                s[j] = a[level][j] + minValue;
                //cout << s[j] << endl;
            }
        }
        return s[0];
    }
};

int main() {
    int a[] = {10,9,2,5,3,7,101,18};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    
    int m=4;
    int n=4;
    int aa[][4] = {
        {2,0,0,0},
        {3,4,0,0},
        {6,5,7,0},
        {4,1,8,3}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    vector< vector<int> > vv2;
    vv2.push_back(vector<int>({1}));
    vv2.push_back(vector<int>({2,3}));
    

    Solution s;
    
    
    int res = 0;
    res = s.minimumTotal(vv2);
    cout << res << endl;
    return 0;
}

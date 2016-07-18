#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>


using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num < 1)
            return false;
        if(num == 1)
            return true;
        
        vector<int> v({2, 3, 5});
        
        for(int i=0; i<v.size();i++) {
            while(num %v[i] == 0) {
                num = num / v[i];
            }
        }
        
        bool flag = false;
        if(num == 1)
            flag = true;
        
        return flag;
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
    for(int i=0; i <= 100; i++) {
        bool flag = s.isUgly(i);
        cout << i <<":" << flag << endl;
    }
    cout << res << endl;
    return 0;
}

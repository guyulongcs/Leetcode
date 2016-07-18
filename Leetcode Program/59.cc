#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stack>

const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vv=vector<vector<int>>(n, vector<int>(n, 0));
        if(n==0)
            return vv;
        
        int i=0;
        int j=0;
        bool flag = true;
        
        int circle = 0;
        int direct = RIGHT;
        int cnt = 0;
        
        while(flag) {
            vv[i][j] = cnt+1;
            flag = getNextPos(n, n, i, j, circle, direct, cnt);
        }
        return vv;
        
    }

    bool getNextPos(int m, int n, int & i, int& j, int & circle, int & direct, int & cnt) {
        bool flag = true;
        
        //get direct
        if(direct == UP) {
            if(i == 1+circle) {
                direct = RIGHT;
                circle++;
            }
        }
        else if(direct == DOWN) {
            if(i == m-1-circle) {
                direct = LEFT;
            }
        }
        else if(direct == LEFT) {
            if(j == circle) {
                direct = UP;
            }
        }
        else if(direct == RIGHT) {
            if(j == n-1-circle) {
                direct = DOWN;
            }
        }
        
        //get pos
        if(direct == UP) {
            i--;
        }
        if(direct == DOWN)
            i++;
        if(direct == LEFT)
            j--;
        if(direct == RIGHT)
            j++;
        
        //update
        cnt++;
        
        if(cnt == m*n)
            flag = false;
        
        return flag;
        
        
    }
};

int main() {
    Solution s;
    
    vector<vector<int>> vv = s.generateMatrix(3);
    for(int i=0; i < vv.size(); i++) {
        for(int j=0; j < vv[i].size(); j++) {
            cout << vv[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    
    return 0;
}


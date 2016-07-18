#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        
        int N = matrix.size();
        
        int circle = 0;
        int row=0;
        int col=0;
        for(circle = 0; circle < N/2; circle++){
            vector<int> v = vector<int>(N-circle*2, 0);
            //left->v
            for(row=circle; row <= N-1-circle; row++) {
                v[row-circle] = matrix[row][circle];
            }
            //down->left
            for(col=circle; col <= N-1-circle; col++) {
                matrix[col][circle] = matrix[N-1-circle][col];
            }
            //right->down
            for(row=circle; row <= N-1-circle; row++) {
                matrix[N-1-circle][row] = matrix[N-1-row][N-1-circle];
            }
            //up->right
            for(col=N-1-circle; col >= circle; col--) {
                matrix[col][N-1-circle] = matrix[circle][col];
            }
            //v->up
            for(col=circle; col <= N-1-circle; col++) {
                matrix[circle][col] = v[N-circle*2-1-(col-circle)];
            }
        }
    }

    void printVV(vector<vector<int>>& vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }

    void printV(vector<int>& v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
};


int main() {
    
    Solution s;
    
    vector<vector<int>> vv;
    vv.push_back(vector<int>({1,2,3,4}));
    vv.push_back(vector<int>({5,6,7,8}));
    vv.push_back(vector<int>({9,10,11,12}));
    vv.push_back(vector<int>({13,14,15,16}));
    
    s.rotate(vv);
    s.printVV(vv);
    return 0;
}


#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>


using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        bool flag = false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int rl=0;
        int rh = m-1;
        
        
        bool flagUpdate = false;
        while(true) {
            if(rl > rh || !flagUpdate) {
                break;
            }
            flagUpdate = false;
            int rm = (rl + rh) / 2;
            if(matrix[rm][0] < target) {
                rl = rm;
                flagUpdate = true;
            }
            else if(matrix[rm][0] == target) {
                flag = true;
                break;
            }
            else {
                rh = rm-1;
                flagUpdate = true;
            }
        }
        
        for(int r=rl; r<=rh; r++) {
            if(searchRow(matrix, target, r, n)) {
                flag = true;
                break;
            }
        }
        
        
        
        return flag;
    }
    
    bool searchRow(vector<vector<int>>& matrix, int target, int r, int n) {
        bool flag = false;
        int cl = 0 ;
        int ch = n-1;
        while(true) {
            if(cl > ch) {
                break;
            }
            int cm = (cl+ch) /2;
            if(matrix[r][cm] < target) {
                cl = cm+1;
            }
            else if(matrix[r][cm] == target) {
                flag = true;
                break;
            }
            else {
                ch = cm-1;
            }
            
        }
        
        return flag;
    }
    
    
    void printVV(vector<vector<int>> & vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
    
    void printV(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
};



int main() {

    Solution s;

    vector<vector<int>> vv;
    vv.push_back(vector<int>({1,3,5,7}));
    vv.push_back(vector<int>({10,11,16,20}));
    vv.push_back(vector<int>({23,30,34,50}));

    bool res = s.searchMatrix(vv, 8);
    cout << res << endl;
    
    return 0;
}

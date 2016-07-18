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
    void setZeroes(vector< vector<int> >& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        
        set<int> sr;
        set<int> sc;
        vector<int> flagC(n, false);

        for(int i = 0; i < m; i++) {
            for(int j=0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    sr.insert(i);
                    sc.insert(j);
                }
            }
        }
        
        
        for(set<int>::iterator it = sr.begin(); it != sr.end(); it++) {
            int r = *it;
            for(int j=0; j < n; j++) {
                matrix[r][j] = 0;
            }
        }
        
        for(set<int>::iterator it = sc.begin(); it != sc.end(); it++) {
            int c = *it;
            for(int j=0; j < m; j++) {
                matrix[j][c] = 0;
            }
        }
  
    }
};


int main() {

    Solution s;
  
    vector< vector<int> > matrix;
    
    
    s.setZeroes(matrix);
    

    return 0;
}


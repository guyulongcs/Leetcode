#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int h = matrix.size();
        int w = matrix[0].size();
        return searchMatrixWH(matrix, target, 0, h-1, 0, w-1);
    }
    
    bool searchMatrixWH(vector<vector<int>>& matrix, int target, int h1, int h2, int w1, int w2) {
        bool flag = false;
        if(h1 > h2 || w1 > w2) {
            return false;
        }
        
        bool flagUpdate = false;
        while(true) {
            flagUpdate = false;
            if(matrix[h1][w2] < target) {
                if(h1+1 <= h2) {
                    h1++;
                    flagUpdate = true;
                }
            }
            int hm = (h1+h2) / 2;
            if(matrix[hm][0] == target) {
                flag = true;
                break;
            }
            else if(matrix[hm][0] > target) {
                if(hm-1 >= h1) {
                    h2 = hm-1;
                    flagUpdate = true;
                }
            }
            if(!flagUpdate) {
                break;
            }
        }
        
        for(int h=h1; !flag && h <= h2; h++) {
            flag = searchMatrixW(matrix, target, h, w1, w2);
        }

        return flag;
    }
    
    bool searchMatrixW(vector<vector<int>>& matrix, int target, int h, int w1, int w2) {
        bool flag = false;
        while(true) {
            int wm = (w1+w2) / 2;
            if(matrix[h][wm] < target) {
                w1 = wm + 1;
            }
            else if(matrix[h][wm] == target) {
                flag = true;
                break;
            }
            else {
                w2 = wm - 1;
            }
            if(w1 > w2)
                break;
        }
        
        return flag;

    }
    
};

void printVector(vector<int> v) {
    for(int i=0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
}

int main() {
    Solution s= Solution();
    
    int k=0;
    vector<int> v1({1, 4,  7, 11, 15});
    vector<int> v2({2,   5,  8, 12, 19});
    vector<int> v3({3,   6,  9, 16, 22});
    vector<int> v4({10, 13, 14, 17, 24});
    vector<int> v5({18, 21, 23, 26, 30});

    vector< vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    
    
    int N = v1.size();
    
    int target = 20;
   
    bool res = s.searchMatrix(v, target);
    cout << res << endl;
    return 0;
}


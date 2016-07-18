#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <set>
#include <cmath>
using namespace std;


class Solution {
public:
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        
        int res=INT32_MIN;

        getSubMatrixK(matrix, m, n, k, res);
        return res;
    }
    
    void getMatrixSum(vector<vector<int>>& matrix, int m, int n, vector<vector<long long>>& s) {
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                s[i][j] = matrix[i][j];
                if(i > 0)
                    s[i][j] += s[i-1][j];
                if(j > 0)
                    s[i][j] += s[i][j-1];
                if(i > 0 && j > 0)
                    s[i][j] -= s[i-1][j-1];
            }
        }
    }
    
    void getSubMatrixK(vector<vector<int>>& matrix, int m, int n, int k, int & res) {
        for(int j=0; j < n; j++) {
            vector<int> v(m, 0);
            for(int j2=j; j2 < n; j2++) {
                set<int> s{0};
                int curSum =0;
                int curMax = INT32_MIN;
                
                for(int i=0; i < m; i++) {
                    v[i] += matrix[i][j2];
                    curSum += v[i];
                    auto it = s.lower_bound(curSum-k);
                    if(it != s.end()) {
                        curMax = max(curSum - (*it), curMax);
                    }
                    s.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
    }
    
    void printV(vector<long long> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    void printVV( vector< vector<long long> >  & vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
};


int main() {

    Solution s;

    vector<vector<int>> vv;
    int k;
    
//    
//    vv.push_back({2,2,-1});
//    vv.push_back({0,-2,3});
//    k = 2;
    
    vv.push_back({1,0,1});
    vv.push_back({0,-2,3});
    k=2;
    
    int res = s.maxSumSubmatrix(vv, k);
    cout << res << endl;

    return 0;
    
}

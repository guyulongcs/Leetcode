#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>


using namespace std;

class Solution {
public:
    
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> vv;
        
        vector<int> candidates;
        for(int i=1; i <= 9; i++) {
            candidates.push_back(i);
        }
        
        int N = candidates.size();
    
        vector<int> v;
        
        dfs(candidates, 0, N-1, k, target, v, vv);
        return vv;
    }
    
    void dfs(vector<int>& nums, int b, int e, int k, int target, vector<int> v, vector<vector<int>>& vv) {
        
        if(target == 0 && k==0) {
            vv.push_back(v);
            return;
        }
        
        if(b > e || target < 0 || k==0) {
            return;
        }
        
        v.push_back(nums[b]);
        dfs(nums, b+1, e, k-1, target-nums[b], v, vv);
        
        v.erase(v.begin()+v.size()-1);
        dfs(nums, b+1, e, k, target, v, vv);
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


    vector<vector<int>> res = s.combinationSum3(3, 7);
    s.printVV(res);

    return 0;
}

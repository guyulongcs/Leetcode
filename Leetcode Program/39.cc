#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>


using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vv;
        int N = candidates.size();
        if(N==0)
            return vv;
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> v;
        
        dfs(candidates, 0, N-1, target, v, vv);
        return vv;
    }
    
    void dfs(vector<int>& nums, int b, int e, int target, vector<int> v, vector<vector<int>>& vv) {

        if(b > e || target < 0) {
            return;
        }
        
        if(target == 0) {
            vv.push_back(v);
            return;
        }

        v.push_back(nums[b]);
        dfs(nums, b, e, target-nums[b], v, vv);
        
        v.erase(v.begin()+v.size()-1);
        dfs(nums, b+1, e, target, v, vv);
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
    
    vector<int> v({2,3,6,7});
 
    vector<vector<int>> res = s.combinationSum(v, 7);
    s.printVV(res);
    
    return 0;
}

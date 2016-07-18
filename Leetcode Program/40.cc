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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> vv;
        int N = candidates.size();
        if(N==0)
            return vv;
        
        map<int, int> itemCntMap;
        for(int i=0; i < N;i++) {
            int num = candidates[i];
            if(itemCntMap.find(num) == itemCntMap.end()) {
                itemCntMap[num]=0;
            }
            itemCntMap[num]+=1;
        }
        vector<int> nums;
        for(map<int, int>::iterator it = itemCntMap.begin(); it != itemCntMap.end(); it++) {
            nums.push_back(it->first);
        }
        
        sort(nums.begin(), nums.end());
        
        N=nums.size();
        
        vector<int> numSum(nums.size()+1, 0);
        getSum(nums, itemCntMap, numSum);
        
//                printV(nums);
//                printV(numSum);
        
        vector<int> v2;
        vector<vector<int>> cur;
        dfs(nums, itemCntMap, numSum, 0, N-1, target, v2, cur, vv);
        
        
        return vv;
    }
    
    void getSum(vector<int> & nums, map<int, int>  & itemCntMap, vector<int> & numSum) {
        
        for(int i=nums.size()-1; i >=0; i--) {
            int cur=0;
            if(itemCntMap.find(nums[i]) != itemCntMap.end()) {
                cur += itemCntMap[nums[i]] * nums[i];
                
            }
            //            cout << "cur:" << cur << endl;
            numSum[i] = cur;
            if(i != nums.size()-1) {
                numSum[i] += numSum[i+1];
            }
            
            
        }
    }
    
    void addVV(vector<vector<int>>& vv, vector<vector<int>>& cur) {
        for(int i=0; i < cur.size();i++) {
            vv.push_back(cur[i]);
        }
    }
    void dfs(vector<int>& nums, map<int, int> itemCntMap, vector<int>& numSum, int b, int e, int target, vector<int> v, vector<vector<int>>& cur, vector<vector<int>>& vv) {
        
        
        if(b > e || target < 0) {
            return;
        }
        
        
        if(target == 0) {
            
            cur.push_back(v);

            addVV(vv, cur);
            
            
            return;
        }
        
        int itemCnt = 0;
        if(itemCntMap.find(b) != itemCntMap.end()) {
            itemCnt = itemCntMap[b];
        }
     
        
        vector< vector<int> > tmp;
        
        if(itemCntMap[nums[b]] > 0 && target >= nums[b]) {
            v.push_back(nums[b]);
//            cout << "use:" << nums[b] << endl;
            
            itemCntMap[nums[b]]-=1 ;
            dfs(nums, itemCntMap, numSum,  b, e, target-nums[b], v, tmp, vv);
            itemCntMap[nums[b]]+=1;
            
            v.erase(v.begin()+v.size()-1);
        }
        
        
        if(numSum[b+1] >= target) {
            dfs(nums, itemCntMap, numSum, b+1, e, target, v, tmp, vv);
        }
        

        
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

    vector<int> v({1,1,1,3,5});

    vector<vector<int>> res = s.combinationSum2(v, 8);
    s.printVV(res);
    
    return 0;
}

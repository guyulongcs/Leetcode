#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> mapNumCnt;
        getMapNumCnt(nums, mapNumCnt);
  
        vector<vector<int>> vv;
        getSubSet(mapNumCnt, vv);
        
        return vv;
    }
    
    
    void getMapNumCnt(vector<int>& nums, map<int, int> & mapNumCnt) {
        for(int i=0; i < nums.size(); i++) {
            int num = nums[i];
            if(mapNumCnt.find(num) == mapNumCnt.end()) {
                mapNumCnt[num] = 0;
            }
            mapNumCnt[num]++;
        }
    }
    
    void getSubSet(map<int, int> & mapNumCnt, vector<vector<int>> & vv) {
        vector<int> vc;
        vector<vector<int>> vvc;
        vvc.push_back(vc);
        mergeVV(vvc, vv);
        
        for(map<int, int>::iterator it = mapNumCnt.begin(); it != mapNumCnt.end(); it++) {
            int num = it->first;
            int cnt = it->second;
            
            vector<vector<int>> vvc = vv;
            vector<vector<int>> vvnew;
            for(int j=1; j <= cnt; j++) {
                for(int i=0; i < vvc.size(); i++) {
                    vector<int> old = vvc[i];
                    for(int k=1; k <= j; k++) {
                        old.push_back(num);
                    }
                    vvnew.push_back(old);
                }
            }
            mergeVV(vvnew, vv);
        }
    }
    
    void mergeVV(vector<vector<int>> & vvnew, vector<vector<int>> & vv) {
        for(int i=0; i < vvnew.size(); i++) {
            vv.push_back(vvnew[i]);
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
    

    vector<int> v({1,2,2});
    
    vector<vector<int>> res = s.subsetsWithDup(v);
    s.printVV(res);

    return 0;
}


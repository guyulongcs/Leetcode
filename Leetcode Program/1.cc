#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int N=nums.size();
        
        bool flag = false;
        for(int i=0; !flag && i<N; i++) {
            for(int j=i+1; !flag && j < N; j++) {
                if(nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    flag = true;
                    break;
                }
            }
        }
        return res;
    }
};


int main() {
    

    Solution s;
    vector<int> v1({1,0,1,2});
    vector<int> v2({});
    vector<int> v = s.twoSum(v1, 3);

    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
    
    
    return 0;
}


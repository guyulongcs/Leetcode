#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void wiggleSort2(vector<int>& nums) {
        int N = nums.size();
        vector<int> snums(N, 0);
        
        for(int i=0; i < N; i++) {
            snums[i] = nums[i];
        }
        sort(snums.begin(), snums.end());
        
        
        int j=N-1;
        for(int i=1; i < N; i+=2, j--) {
            nums[i] = snums[j];
        }
        for(int i=0; i < N; i+=2, j--) {
            nums[i] = snums[j];
        }
    }
    
};


int main() {


    Solution s;

    vector<int> v({1,3,2,2,3,1});
    s.wiggleSort(v);
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N=nums.size();
        int maxN = (1 << N) - 1;
        vector< vector<int> > res;
        for(int i=0; i <= maxN; i++) {
            vector<bool> v = getBits(i, N);
            vector<int> vn = getVector(nums, v, N);
            res.push_back(vn);
        }
        return res;
    }
    
    vector<bool> getBits(int num, int N) {
        vector<bool> bits(N, 0);
        int i=0;
        while(num) {
            bits[i] = num % 2;
            num = num / 2;
            i++;
        }
        return bits;
    }
    
    vector<int> getVector(vector<int>& nums, vector<bool> v, int N){
        vector<int> res;
        for(int i=0; i < N; i++) {
            if(v[i]) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
    
    
    
    
    void printVecInt(vector<int> v) {
        for(int i=0; i < v.size(); i++) {
            cout << int(v[i]) << "\t";
        }
        cout << endl;
    }

};



int main() {
    Solution s= Solution();
    
    vector<int> nums({3,2,1});
    
    vector< vector<int> > res = s.subsets(nums);
    
    for(int i=0; i < res.size(); i++) {
        s.printVecInt(res[i]);
    }
    
    return 0;
}



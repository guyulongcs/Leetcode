#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        if( N == 0)
            return 1;

        //replace
        int res = 0;
        for(int i=0; i < N; ) {
            if(nums[i] <= 0 || nums[i] > N || nums[i] == i+1) {
                i++;
            }
            else {
                if( (nums[i]-1 >= 0) && (nums[i] != nums[nums[i]-1]) ) {
                    swap(nums[i], nums[nums[i]-1]);
                }
                else {
                    i++;
                }
            }
        }
        
        //find
        int i;
        for(i=0; i < N; i++) {
            if(nums[i] != i+1) {
                break;
            }
        }
        if(i == N) {
            res = N+1;
        }
        else {
            res = i+1;
        }
        
        //return
        return res;
    }
    
    void printVec(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
};

int main() {
    Solution s;
    vector<int> v({0, 1, 2});

    int res = s.firstMissingPositive(v);
    cout << res << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int N = nums.size();
        if(N == 0)
            return res;
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(N, 1);
        vector<int> pre(N, -1);
        
        int maxLen = 0;
        int maxEnd = 0;
        for(int i=0; i < N; i++) {
            for(int j=i-1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                        if(dp[i] > maxLen) {
                            maxEnd = i;
                            maxLen = dp[i];
                        }
                    }
                }
            }
        }
        
        //res
        int index=maxEnd;
        while(index != -1) {
            res.push_back(nums[index]);
            index = pre[index];
        }
        reverse(res.begin(), res.end());
        
        return res;
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
    
    vector<int> res;
    
    vector<int> v1;
    
    v1= vector<int>({2,3,4,9,11,16});
    res = s.largestDivisibleSubset(v1);
    s.printV(res);
    
    v1= vector<int>({1});
    res = s.largestDivisibleSubset(v1);
    s.printV(res);
    
    return 0;
}


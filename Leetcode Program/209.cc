#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return 0;
        int res = INT32_MAX;
        
       
        int left=0;
        int right = 0;
        
        int sum=0;
        
        for(int right = 0; right < N; right++) {
            sum += nums[right];
            if(sum >= target) {
                while(left <= right && sum >= target) {
                    //cout << left << "\t" << right << endl;
                    res = min(res, right-left+1);
                    sum -= nums[left++];
                }
                
            }
        }
        if(res == INT32_MAX)
            res = 0;
        
        return res;
    }
    int minSubArrayLen2(int target, vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return 0;
        int res = 0;
        
        //cout << N << endl;
        //s
        vector<int> s(N+1, 0);
        s[0] = 0;
        for(int i=1; i <= N; i++) {
            s[i] = s[i-1] + nums[i-1];
        }
        
        //cout << s[5] << endl;
        //find
        bool flag = false;
        for(int k=1; !flag && k <= N; k++) {
            for(int i=1; i <= N-k+1; i++) {
                int j = i+k-1;
                int cur = s[j] - s[i-1];
                if(cur >= target) {
                    flag = true;
                    res = k;
                    break;
                }
            }
        }
        return res;
    }
    
};



int main() {
    Solution s= Solution();
    int target=2;
    vector<int> v({1,4,4});
    int res = s.minSubArrayLen(target, v);
    cout << res << endl;
    return 0;
}


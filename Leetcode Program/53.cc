#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=0;
        int N = nums.size();
        if(N == 0)
            return 0;
        
        int e=nums[0];
        int s=nums[0];
        for(int i=1; i < N; i++) {
            e = max(e+nums[i], nums[i]);
            s = max(s, e);
        }
        res = s;
        return res;
    }
};

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    
    Solution s;
    
    
    int res = 0;
    res = s.maxSubArray(v);
    cout << res << endl;
    return 0;
}

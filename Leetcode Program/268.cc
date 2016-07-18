class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        long long sum = N * (N+1) / 2;
        for (int i=0; i < N; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};

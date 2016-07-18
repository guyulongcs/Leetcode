#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int maxProfit = 0;
        if(N <= 0)
            return 0;
        int b=prices[0];
        for(int i=1; i < N; i++) {
            if(prices[i] < b)
                b = prices[i];
            int p = prices[i] - b;
            if(p > maxProfit)
                maxProfit = p;
        }
        return maxProfit;
    }
};

int main() {
    int a[6] = {3,4,2,6};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    Solution s= Solution();
    
    int res = 0;
    res = s.maxProfit(nums);
    
    
    cout << res << endl;
    
    
    return 0;
}


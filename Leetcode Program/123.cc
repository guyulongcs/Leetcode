#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int res =0;
        int N = prices.size();
        if(N == 0)
            return 0;
        
        int * pre = new int[N];
        int * post = new int[N+1];
        
        int bmin= prices[0];
        pre[0] = 0;
        for(int i=1; i<N;i++) {
            if(prices[i] < bmin) {
                bmin = prices[i];
            }
            pre[i] = pre[i-1];
            int p2 = prices[i] - bmin;
            if(p2 > pre[i])
                pre[i] = p2;
        }
        
        int smax = prices[N-1];
        post[N] = 0;
        post[N-1]=0;
        for(int i=N-2;i>=0;i--) {
            if(prices[i] > smax)
                smax=prices[i];
            post[i] = post[i+1];
            int p2 = -prices[i] + smax;
            if(p2 > post[i])
                post[i] = p2;
        }
        
        
        for(int i=0; i<N;i++) {
            int total = pre[i] + post[i+1];
            if(total > res)
                res = total;
        }
        
        
        delete [] pre;
        delete [] post;
        
        return res;
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


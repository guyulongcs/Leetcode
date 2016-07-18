#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int N = prices.size();
        if(N == 0)
            return 0;
       
        int * b = new int[N];
        int * s = new int[N];
        
        b[0]=-prices[0];
        s[0]=0;
        
       
        
        for(int i=1; i < N; i++) {
            int delta = prices[i] - prices[i-1];
            b[i] = b[i-1] - delta;
            if(i >=2 ) {
                int tmp = s[i-2] - prices[i];
                if(tmp > b[i])
                    b[i] = tmp;
            }
            
            s[i] = max(b[i-1] + prices[i], s[i-1] + delta);
        }
        
        int maxP = 0;
        for(int i=0; i < N;i++) {
            //cout << s[i] << " ";
            if(s[i] > maxP)
                maxP = s[i];
        }
        //cout << endl;
        
        delete []b;
        delete []s;
        
        res = maxP;
        return res;
    }
    
};

int main() {
    Solution s = Solution();
    int a[] = {1, 2, 3, 0, 2};
    vector<int> p(a, a + sizeof(a) / sizeof(int));
    int res = s.maxProfit(p);
    cout << res << endl;
    return 0;
}

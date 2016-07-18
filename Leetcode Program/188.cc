#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res = 0;
        int N = prices.size();
        
        if(k==0 || N == 0)
            return 0;
        
        k=min(k, N);
        
        if(k >= N/2) {
            for(int i=1; i < N; i++) {
                res += max(prices[i]-prices[i-1], 0);
            }
            return res;
        }
        
        int ** global = new int * [2];
        int ** local = new int * [2];
        
        for(int i=0; i<2; i++) {
            global[i] = new int[k+1];
            local[i] = new int[k+1];
        }
        
        for(int i=0; i<N;i++) {
            local[0][0] = 0;
            global[0][0] = 0;
            if(i == 0) {
                 for(int j=1; j<=k;j++) {
                     global[0][j] = 0;
                     local[0][j] = 0;
                 }
            }
            else{
                int diff = prices[i] - prices[i-1];
                for(int j=1; j<=k;j++) {
                    local[1][j] = max(global[0][j-1] + max(diff, 0), local[0][j] + diff);
                    global[1][j] = max(local[1][j], global[0][j]);
                  
                }
                for(int j=1; j<=k; j++) {
                    local[0][j] = local[1][j];
                    global[0][j] = global[1][j];
                }
                
            }
        }
        
        res = global[1][k];
        
        return res;
    }
    
    void printVec(vector<int> v) {
        cout << "vec" << endl;
        for(int i=0; i < v.size();i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    
};

int main() {
    Solution s = Solution();
    int a[] = {3,2,6,5,0,3};
    vector<int> p(a, a + sizeof(a) / sizeof(int));
    int res = s.maxProfit(2, p);
    cout << res << endl;
    return 0;
}

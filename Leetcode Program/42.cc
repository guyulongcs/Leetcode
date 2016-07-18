#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
  
        int N = height.size();
        
        if(N <= 1) {
            return 0;
        }
        
        //hl, hr
        vector<int> hl(N+1, 0);
        vector<int> hr(N+1, 0);
        getMaxHighLeft(height, hl, hr, N);
        
        //get water
        int res = getWater(height, hl, hr, N);
        
        return res;
    }
    
    
    
    void getMaxHighLeft(vector<int> & height, vector<int> & hl, vector<int> & hr, int N) {
        hl[0] = 0;
        hr[N-1] = 0;
        
        for(int i=1; i < N; i++) {
            hl[i] = max(hl[i-1], height[i-1]);
        }
        
        for(int i=N-2; i >= 0; i--) {
            hr[i] = max(hr[i+1], height[i+1]);
        }
    }
    
    int getWater(vector<int> & height, vector<int> & hl, vector<int> & hr, int N) {
        int sum=0;
        for(int i=1; i < N-1; i++) {
            int left = hl[i];
            int right = hr[i];
            int cur = height[i];
            
            int diff = max(min(left, right) - cur, 0);
            sum += diff;
        }
        return sum;
    }

};


int main() {

    Solution s;
    vector<int> v({0,1,0,2,1,0,1,3,2,1,2,1});
    
    int res = s.trap(v);
    cout << res << endl;

    return 0;
}



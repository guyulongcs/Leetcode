#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;




class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int N = height.size();
        if(N <= 1)
            return 0;
        
        int i=0;
        int j=N-1;
        while(true) {
            
            int area = min(height[i], height[j]) * (j-i);
            res = max(res, area);
            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
            if(i >= j)
                break;
        }
        return res;
    }
};


int main() {

    Solution s;

    return 0;
}


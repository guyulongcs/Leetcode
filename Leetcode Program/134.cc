#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size())
            return -1;
        
        int N = gas.size();
        int sum=0;
        int start = 0;
        int total = 0;
        for(int i=0; i < N; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            if(sum < 0) {
                sum = diff;
                start = i;
            }
            else {
                sum += diff;
            }
        }
        if(total < 0)
            return -1;
        else
            return start;
        
    }
};

int main() {
    Solution s= Solution();
    return 0;
}



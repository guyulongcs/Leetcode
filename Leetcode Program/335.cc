#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int N = x.size();
        
        for(int i=0; i < N; i++) {
            if(i >= 3 && x[i-3] >= x[i-1] && x[i] >= x[i-2])
                return true;
            if(i >= 4 && x[i-3] == x[i-1] && (x[i-4] + x[i] >= x[i-2]))
                return true;
            if(i >= 5 && x[i-4] < x[i-2] && x[i-1] < x[i-3] && (x[i] + x[i-4] >= x[i-2]) && (x[i-5] + x[i-1] >= x[i-3]))
                return true;
        }
        return false;
        
    }
};


int main() {
    Solution sol;
    
    vector<int> v;
    bool res;
    
    
    v = vector<int>({2, 1, 1, 2});
    res = sol.isSelfCrossing(v);
    cout << res << endl;
    
      return 0;
}


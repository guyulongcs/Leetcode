#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        int N = nums.size();
        if(N == 0) {
            return v;
        }
        
        int s=nums[0];
        int e=nums[0];
        for(int i=1; i < N; i++) {
            int n = nums[i];
            if(n == e+1) {
                e++;
            }
            else {
                addV(s, e, v);
                s = n;
                e = n;
            }
        }
        addV(s, e, v);
        return v;
    }
    
    void addV(int s, int e, vector<string> & v) {
        
        string str;
        if(s < e)
            str = to_string(s) + "->" + to_string(e);
        else
            str = to_string(s);
        v.push_back(str);
    }
};

int main() {


    Solution s;
    
    vector<int> v({0, 1, 2, 4, 5, 7});
    int n;
    vector<string> res;
    res = s.summaryRanges(v);
    for(int i=0; i < res.size(); i++)
        cout  << res[i] << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        vector<int> vj;
        for(unordered_set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
            if(s2.find(*it) != s2.end()) {
                vj.push_back(*it);
            }
        }
        return vj;
    }
};


int main() {
    

    Solution s;
    vector<int> v1({1,2,2,1});
    vector<int> v2({});
    vector<int> vj = s.intersection(v1,v2);
    
    for(int i=0; i<vj.size();i++) {
        cout << vj[i] << "\t";
    }
    cout << endl;
    
    
    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0;
        int c1=0;
        int c2=0;
        vector<int> c(3, 0);
        for(int i=0; i < nums.size(); i++ ) {
            c[nums[i]]++;
        }
        
        int k=0;
        for(int j=0; j <= 2; j++) {
            for(int i=0; i < c[j]; i++) {
                nums[k++] = j;
            }
        }
    }
};


int main() {
    

    Solution s;
    vector<int> v({1,0,1,2,0,1,1});
 
    s.sortColors(v);
    
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }

    return 0;
}


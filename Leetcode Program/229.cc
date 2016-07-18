#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size();
        vector<int> v;
        if(N == 0)
            return v;
 
        
        findMajorityElement(nums, N, v);
        return v;
    }
    
    void findMajorityElement(vector<int>& nums, int N, vector<int> & v) {
        int cnt=0;
        int n=nums[0];
        
        int c1=0;
        int c2=0;
        
        int n1=0;
        int n2=0;
        for(int i=0; i < N; i++) {
            int num = nums[i];
            if(num == n1) {
                c1++;
            }
            else if(num == n2){
                c2++;
            }
            else if(c1 == 0) {
                n1 = num;
                c1++;
            }
            else if(c2 == 0) {
                n2 = num;
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        
//        cout << n1 << "\t" << n2 << endl;
        
        
        c1=0;
        c2=0;
        for(int i=0; i < nums.size(); i++) {
            if(n1 == nums[i])
                c1++;
            if(n2 == nums[i])
                c2++;
        }
//        cout << c1 << "\t" << c2 << endl;
        
        if(c1 > N/3)
            v.push_back(n1);
        if(c2 > N/3 && n2 != n1)
            v.push_back(n2);
    }
};

int main() {


    Solution s;
    vector<int> v({4,2,1,1});
    int n=1;

    vector<int> res= s.majorityElement(v);
    for(int i=0; i < res.size(); i++) {
        cout << res[i] << endl;
    }


    return 0;
}



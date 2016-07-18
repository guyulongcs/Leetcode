#include <iostream>
//#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS2(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int res=0;
        int N = nums.size();
        
        int * e = new int[N];
        int s = 1;
        for(int j=0; j < N;j++) {
            e[j] = 1;
            for(int k=j-1; k >= 0; k--) {
                if(nums[k] < nums[j]) {
                    e[j] = max( e[j], e[k] + 1);
                }
            }
            s = max(s, e[j]);
        }
        res = s;
        return res;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int res=0;
        int N = nums.size();
        
        int * e = new int[N];
        int l = 0;
        
        
        for(int j=0; j < N;j++) {
            int pos = findBinaryPos(e, 0, l-1, nums[j]);
            e[pos] = nums[j];
            if(pos == l)
                l+=1;
            //cout << j << "," << pos << "," << l << endl;
        }
        res = l;
        return res;
    }
    
    int findBinaryPos(int * p, int left, int right, int value) {
        int res = 0;
     
        
        while(left <= right) {
            int middle = (left + right) / 2;
            if(p[middle] < value) {
                left = middle + 1;
            }
            else if(p[middle] == value) {
                res = middle;
                break;
            }
            else {
                right = middle-1;
            }
        }
        if(left > right)
            res = right + 1;
        return res;
    }

};

int main() {
    int a[] = {10,9,2,5,3,7,101,18};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    
    int m=3;
    int n=3;
    int aa[][3] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    
    Solution s;
    
    
    int res = 0;
    res = s.lengthOfLIS(v);
    cout << res << endl;
    return 0;
}

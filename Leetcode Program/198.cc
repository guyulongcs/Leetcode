#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        int * a = new int[N];
        memset(a, 0, sizeof(int) * N);
        //setArrayValue(a, N, -1);
        
        int res = robFunc(nums, a, N);
        delete []a;
        
        return res;
    }
    
    void setArrayValue(int * a, int n, int value) {
        for(int i=0; i < n; i++)
            a[i]=value;
        
    }
    
    int robFunc(vector<int>& nums, int * a, int n) {
        
        for(int l = 0; l < n; l ++) {
            int v1=nums[l];
            int v2 =0;
            if(l >= 2)
                v1 += a[l-2];
            if(l >= 1)
                v2 = a[l-1];
            int maxValue = (v1 > v2) ? v1: v2;
            a[l] = maxValue;
        }
        int res = a[n-1];
        return res;
        
    }
};

int main() {
    Solution s = Solution();
    
    int a[] = {2,3,4,5,1};
    
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    
    int res = s.rob(v);
    cout << res << endl;
}


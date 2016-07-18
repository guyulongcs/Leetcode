#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        int * a = new int[N];
                //setArrayValue(a, N, -1);
        
        int res = robFuncCircle(nums, a, N);
        delete []a;
        
        return res;
    }
    
    void setArrayValue(int * a, int n, int value) {
        for(int i=0; i < n; i++)
            a[i]=value;
        
    }
    
    int robFuncCircle(vector<int>& nums, int * a, int N) {
        if(N == 0)
            return 0;
        if(N == 1)
            return nums[0];
        
        int v1 = nums[0] + robFunc(nums, a, N, 2, N-2);
        int v2 = nums[N-1] + robFunc(nums, a, N, 1, N-3);
        int v3 = robFunc(nums, a, N, 1, N-2);
        int v = getMax(v1, v2);
        v = getMax(v, v3);
        return v;
    }
    
    int robFunc(vector<int>& nums, int * a, int N, int low, int high) {
        if(low > high) {
            return 0;
        }
        memset(a, 0, sizeof(int) * N);
        
        for(int l = low; l <= high; l++) {
            int v1=nums[l];
            int v2 =0;
            
            if((l-low) >= 2)
                v1 += a[l-2];
            
            if((l-low) >= 1)
                v2 = a[l-1];
            
            int maxValue = (v1 > v2) ? v1: v2;
            a[l] = maxValue;
        }
        int res = a[high];
        return res;
        
    }
    
    int getMax(int v1, int v2) {
        int res = (v1 > v2) ? v1 : v2;
        return res;
    }
};

int main() {
    Solution s = Solution();

    int a[] = {1,1,1};

    vector<int> v(a, a + sizeof(a) / sizeof(int));

    int res = s.rob(v);
    cout << res << endl;
}


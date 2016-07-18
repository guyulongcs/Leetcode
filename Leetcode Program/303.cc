#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;



class NumArray {
public:
    //vector<int> a;
    int * s;
    NumArray(vector<int> &nums) {
        int N = nums.size();
        
        //init
        s = new int[N];
        int sum = 0;
        for(int i=0; i < N; i++) {
            sum += nums[i];
            s[i] = sum;
        }
        
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        if(j < i)
            return 0;
        if(i <= 0 )
            res = s[j];
        else
            res = s[j] - s[i-1];
        return res;
    }
};

int main() {
    int a[6] = {-2, 0,3,-5,2,-1};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    NumArray numArray(nums);
    int res = 0;
    res = numArray.sumRange(2, 5);
    
    
    cout << res << endl;
    
    
    return 0;
}


#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        if(N <= 1)
            return;
        k = k % N;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }

    void rotate2(vector<int>& nums, int k) {
        int N = nums.size();
        if(N <= 1)
            return;
        k = k % N;
        
        int rightCnt = k;
        int leftCnt = N-k;
        if(k <= N/2) {
            
            for(int i=0; i < rightCnt; i++) {
                shiftRight(nums, N);
            }
        }
        else{
            for(int i=0; i < leftCnt; i++) {
                shiftLeft(nums, N);
            }

        }
        
    }
    
    void shiftRight(vector<int>& a, int N) {
        if(N <= 1)
            return;
        
        int tmp = a[N-1];
        for(int i=N-2; i >=0; i--) {
            a[i+1] = a[i];
        }
        a[0] = tmp;
    }
    
    void shiftLeft(vector<int>& a, int N) {
        if(N <= 1)
            return;
        
        int tmp = a[0];
        for(int i=0; i <= N-2; i++) {
            a[i] = a[i+1];
        }
        a[N-1] = tmp;
    }
    
};

int main() {

    
    Solution s;
    vector<int> v({1,2,3,4,5,6,7});
    
    s.rotate(v, 3);
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    
    return 0;
}

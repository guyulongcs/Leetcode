#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = 0;
    int N = nums.size();
    if(N < 1)
        return n;
    
    n = nums[0];
    int cnt = 1;
    for (int i=1; i < N; i++) {
        if(nums[i] == n) {
            cnt++;
        }
        else {
            cnt--;
            if(cnt == 0) {
                n = nums[i];
                cnt++;
            }
        }
    }
    return n;
}

int main(int argc, const char * argv[]) {
    int a[] = {3,3,4};
    vector<int> v(a, a+3);
    int n = majorityElement(v);
    cout << n << endl;
    return 0;
}


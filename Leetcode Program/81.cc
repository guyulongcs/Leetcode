#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>


using namespace std;

class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int N = nums.size();
        int index=-1;
        
        int b = 0;
        int e = N-1;
        
        bool flag = searchDouble(nums, target, b, e);
        
        //cout << "target: " << target << ", index:" << index << endl;
        //bool flag = (index >= 0 && index < N);
        
        return flag;
    }
    
    bool searchDouble(vector<int>& nums, int target, int b, int e) {
        if(b > e) {
            return false;
        }
        bool flag = false;
        int index=-1;
        while(b <= e) {
            int m = b + (e-b)/2;
            if(nums[m] == target) {
                flag = true;
                break;
            }
            else if (nums[m] < nums[e]) {
                if( (target >= nums[m]) && (target <= nums[e]) ) {
                    b = m+1;
                }
                else {
                    e = m -1;
                }
            }
            else if (nums[m] > nums[e]){
                if((target >= nums[b]) && (target < nums[m])) {
                    e = m-1;
                }
                else {
                    b = m+1;
                }
            }
            else if(nums[m] == nums[e]) {
                if(target == nums[b]) {
                    flag = true;
                    break;
                }
                else {
                    b = b + 1;
                }
            }
        }
        
        
        return flag;
    }
    
    void printVV(vector<vector<int>> & vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
    
    void printV(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
};



int main() {

    Solution s;

    vector<int> v({1,1,1,3});
    for (int i = 0; i < v.size(); i++) {
    int num = 4;
        num = v[i];
        bool res = s.search(v, num);
        cout << res<< endl;
    }
    
    bool res = s.search(v, 2);
    cout << res << endl;

    return 0;
}

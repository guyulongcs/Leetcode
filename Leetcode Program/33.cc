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

    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int index=-1;
        
        int b = 0;
        int e = N-1;
        
        index = searchDouble(nums, target, b, e);
        
    
        return index;
    }
    
    int searchDouble(vector<int>& nums, int target, int b, int e) {
        if(b > e) {
            return -1;
        }
        int index=-1;
        while(b <= e) {
            int m = b + (e-b)/2;
            if(nums[m] == target) {
                index = m;
                break;
            }
            else if (nums[m] < nums[e]) {
                if( (target > nums[m]) && (target <= nums[e]) ) {
                    b = m+1;
                }
                else {
                    e = m -1;
                }
            }
            else {
                if((target >= nums[b]) && (target < nums[m])) {
                    e = m-1;
                }
                else {
                    b = m+1;
                }
            }
        }

        
        return index;
    }
    
    int searchOrder(vector<int>& nums, int target, int start, int end) {
        int m = 0;
        int b= start;
        int e= end;
        int index = -1;
        while(true) {
            if(b > e) {
                break;
            }
            m = (b+e) / 2;
            if(nums[m] == target) {
                index = m;
                break;
            }
            else if (nums[m] < target) {
                b = m+1;
            }
            else {
                e = m-1;
            }
        }
        return index;
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
    
    vector<int> v({4,5,6,1,2,3});
    for (int i = 0; i < v.size(); i++) {
    int num = 4;
        num = v[i];
        int res = s.search(v, num);
        cout << res<< endl;
    }
    
    return 0;
}

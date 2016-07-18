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
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if(N <= 1)
            return N;
        
        int pre = nums[0];
        
        int indexValid = 1;
        int index = 1;
        for(index=1; index < N; index++) {
            int num = nums[index];
            if(num != pre) {
                nums[indexValid++] = nums[index];
                pre = nums[index];
            }
        }
        nums.erase(nums.begin() + indexValid, nums.end());
        
        return indexValid;
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
    vector<int> v({1,1,2,2,3,3,5,6});
    int len = s.removeDuplicates(v);
    cout << len << endl;
    s.printV(v);
    
    return 0;
}

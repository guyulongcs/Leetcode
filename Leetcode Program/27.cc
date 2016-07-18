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

    int removeElement(vector<int>& nums, int val) {
        int N = nums.size();
        
        int indexValid = 0;
        int index = 0;
        
        for(index=0; index < N; index++) {
            int num = nums[index];
            if(num != val) {
                nums[indexValid++] = nums[index];
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
    vector<int> v({1,1,1, 2,2,3,3,5,6});
    int len = s.removeElement(v,2);
    cout << len << endl;
    s.printV(v);
    
    return 0;
}

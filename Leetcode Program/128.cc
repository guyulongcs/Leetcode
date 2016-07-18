#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isSetHasNum(unordered_set<int> & setNum, int n) {
        return (setNum.find(n) != setNum.end());
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setNum;
        unordered_set<int> setNumVisited;
        for(int i=0; i < nums.size(); i++) {
            setNum.insert(nums[i]);
        }
        
        int maxLen=0;
        for(unordered_set<int>::iterator it = setNum.begin(); it != setNum.end(); it++) {
            int num = *it;
            if(isSetHasNum(setNumVisited, num)) {
                continue;
            }
            
            int len=1;
            
            //up
            int n=num;
            for(n=num+1; isSetHasNum(setNum, n); n++) {
                setNumVisited.insert(n);
                len++;
            }
            
            //down
            n=num;
            for(n=num-1; isSetHasNum(setNum, n); n--) {
                setNumVisited.insert(n);
                len++;
            }
            
            setNumVisited.insert(num);
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
                   
    

    
};


int main() {

    Solution s;
    vector<int> v({100, 4, 200, 1, 3, 2});
    
    int res = s.longestConsecutive(v);
    cout << res << endl;

    return 0;
}



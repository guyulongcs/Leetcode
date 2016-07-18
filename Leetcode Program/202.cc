#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        
        bool flag = false;
        
        int slow = n;
        int fast = next(n);
        while(slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        flag = (slow == 1);
        
        return flag;
        
    }
    
    int next(int n) {
        vector<int> digits = getDigits(n);
        int sum = getSquaredSum(digits);
        return sum;
        
    }
    
    vector<int> getDigits(int n) {
        vector<int> res;
        while(n > 0) {
            int num = n%10;
            res.push_back(num);
            n = n/10;
        }
        return res;
    }
    
    int getSquaredSum(vector<int> v) {
        int sum=0;
        for(int i =0; i< v.size();i++) {
            sum += v[i] * v[i];
        }
        return sum;
    }
};

int main() {
    Solution s = Solution();
    int res = 0;
    for(int i=1; i<= 20;i++) {
        bool flag = s.isHappy(i);
        cout << "i: " << i << ", flag:" << flag << endl;
    }
    
    
    return 0;
}


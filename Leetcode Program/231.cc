#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag = false;
        if(n <= 0)
            flag = false;
        else if(n == 1)
            flag = true;
        else if(n==2)
            flag = true;
        else {
            int m = n % 2;
            if(m > 0)
                flag = false;
            else
                flag = isPowerOfTwo(n/2);
        }
        return flag;
    }
};

int main() {
    Solution s = Solution();
    int res = 0;
    
    for(int i=0; i < 10; i++) {
        res = s.isPowerOfTwo(i);
        cout << i << " " << res << endl;
    }
    return 0;
}


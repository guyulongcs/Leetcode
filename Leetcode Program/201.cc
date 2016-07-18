#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n>m){
            n=n&(n-1);
        }
        return n;
    }
    
};

int main() {


    Solution s;
    
    int res = s.rangeBitwiseAnd(2147483647,2147483647);
    cout << res << endl;

    
    

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x < y) {
            swap(x, y);
        }
        if(x==z || y == z || z== x+y)
            return true;
        
        if(z > x+y) {
            return false;
        }
        
        int num = gcd(x, y);
        bool flag = false;
        flag = (z % num == 0);
        return flag;
        
    }
    
    int gcd(int x, int y) {
        if(y == 0)
            return x;
        else
            return gcd(y, x %y);
    }
};


int main() {
    Solution s;

    int x, y, z;
    bool res;
    
    x = 3;
    y = 5;
    z = 4;
    res = s.canMeasureWater(x, y, z);
    cout << res << endl;
    
    x = 2;
    y = 6;
    z = 5;
    res = s.canMeasureWater(x, y, z);
    cout << res << endl;
    
    x = 11;
    y = 3;
    z = 13;
    res = s.canMeasureWater(x, y, z);
    cout << res << endl;
    
    return 0;
}


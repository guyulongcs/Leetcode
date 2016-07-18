#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int i= 0;
        int high = 1;
        int tmp = x;
        if(x < 0)
            return false;
        while(x) {
            x=x/10;
            i++;
            if(x > 0) {
                high = high * 10;
            }
        }
//        cout << high << endl;
//        cout << i << endl;
//        
        int n = i;
        int low = 10;
        
        bool flag = true;
        x = tmp;
        while(x) {
            int h = x / high;
            int l = x % low;
//            cout << "h,l:" << h << "\t" << l << endl;
            if(h != l) {
                flag = false;
                break;
            }
            x = x % high;
            x = x / low;
            high = high / 100;
//            cout << x << endl;
//            cout << high << endl;
        }
        return flag;
    }
};

int main() {
    
    
    Solution s;
    
    int a[] = {0};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    
    //cout << v[0] << endl;
    
    int res=0;
    
    

    
    int i = 0;
        res = s.isPalindrome(i);
        cout << i <<"," << res << endl;
    
    cout << endl;

    
    return 0;
}


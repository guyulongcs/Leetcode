#include<iostream>
#include<vector>

#include<iostream>
using namespace std;



class Solution {
public:
    
    int integerBreak(int n) {
        int * a=new int[n+1];
        memset(a, 0, (n+1)*sizeof(int));
        int res = integerBreakRec(n, a);
        return res;
    }

    
    int integerBreakRec(int n, int * a) {
        int res = 0;
        a[1]=1;
        a[2]=1;
        if(a[n] != 0)
            return a[n];
        
        else {
            int max = 1;
            for(int i =1; i <= n/2; i++) {
                int num = i;
                int num1 = maxNum(num, integerBreakRec(num, a));
                num = n - i;
                int num2 = maxNum(num, integerBreakRec(num, a));
                int tmp = num1 * num2;
                max = maxNum(max, tmp);
            }
            res = max;
            a[n] = res;
        }
        return res;
    }
    
    int maxNum(int a, int b) {
        return (a>b)?a:b;
    }

};
int main() {
    Solution s = Solution();
    for (int n=1; n <= 10; n++) {
        int res = s.integerBreak(n);
        cout << "n: " << n << ", res:" << res << endl;
    }
    
}


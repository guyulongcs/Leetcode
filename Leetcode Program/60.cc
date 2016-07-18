#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    string getPermutation(int N, int k) {
//        cout << endl << "k:" << k << endl;
        int n = N;
        vector<long long> f(n, 1);
        getF(f, n);
        
        string res;
        set<int> s;
        for(int i=1; i <= N; i++) {
            s.insert(i);
        }
        while(n >= 1) {
//            cout << endl;
//            cout << "f[n-1]:" << f[n-1] << endl;
            int a = (k-1) / f[n-1];
//            cout << "a:" << a << endl;
            k -= a * f[n-1];
//            cout << "k:" << k << endl;
            auto it = s.begin();
            for(int i=0; i < a ;i++)
                it++;
            int num = *(it);
//            cout << "num:" << num << endl;

            res += to_string(num);
            s.erase(num);
            if(s.empty())
                break;
            n--;
        }
        
//        cout << "res:" << res << endl;
        return res;
                        
            
    }
                        
            
    void getF(vector<long long> & f, int n) {
        f[0] = 1;
        for(int i=1; i <n; i++) {
            f[i] = f[i-1] * i;
        }
    }
};

int main() {


    Solution s;
    string str;
    
    int N = 3;
    for(int k=1; k <= 6; k++) {
        str = s.getPermutation(N, k);
        cout << str << endl;
    }
    return 0;
}


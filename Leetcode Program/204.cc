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
    int countPrimes(int n) {
        vector<bool> f(n+1, true);
        
        int count = 0;
        int m = sqrt(n);
        for(int i=2; i <= m; i++) {
            if(f[i]) {
                for(int j=i*i; j< n;j+=i) {
                    f[j] = false;
                }
            }
            
        }
        for(int i=2; i < n; i++) {
            if(f[i])
                count++;
        }
        return count;
    }
    
    int countPrimes2(int n) {
        vector<bool> f(n+1, true);
        
        int count = 0;
        for(int i=2; i<n; i++) {
            if(i % 2 == 0) {
                continue;
            }
            if(f[i]) {
                f[i] = isPrime(i);
            }
            if(f[i]) {
                count++;
                
            }

 
            long long m=i;
            int k1=i;
            int k2 = n / i;
            for(int k = k1; k<=k2; ) {
                m = i * k;
                f[m] = false;
                k+=2;
            }
        }
        return count;
    }
    
    int isPrime(int n) {
        bool flag = true;
        int m = sqrt(n);
        for(int i=2; i<= m; i++) {
            if(n % m == 0) {
                flag = false;
                break;
            }
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
    int n=2147395599;
    
    int mi=0;
    int ma=100;
    
//    for(int i=mi; i <= ma; i++) {
//        int res2 = s.mySqrt(i);
//
//        cout << i << "\t" << res2 << endl;
//    }
//    for(int i=1;i<=6;i++) {
//    string str = s.getPermutation(3,i) ;
//    
//    cout <<str <<  endl;
//    }
    
    for(int i=1500000; i<= 1500000;i++) {
        int res = s.countPrimes(i) ;
    
        cout <<i << "\t" << res << endl;
    }

    return 0;
}


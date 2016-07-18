#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        if(N == 0)
            return 0;
        vector<int> a(N+1, 0);
        for(int i=0; i < N;i++) {
            int c = citations[i];
            if(c <= N)
                a[c] ++;
        }
        
        //printVec(a);
        
        int sum =0;
        for(int i=0; i <= N; i++) {
            int oldSum = sum;
            sum += a[i];
            a[i] = oldSum;
        }
        
        //printVec(a);
        int h=0;
        for(h=N; h >= 0; h--) {
            
            if(h <= (N-a[h])) {
                break;
            }
        }
        return h;
        
    }
    
    void printVec(vector<int> a) {
        for(int i=0; i < a.size(); i++) {
            cout << a[i] << "\t";
        }
        cout << endl;
    }
};


int main() {
    

    Solution s;
    vector<int> v({1,7,9,2});
 
    int res = s.hIndex(v);
    cout << res << endl;
    
    return 0;
}


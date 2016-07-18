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

        
        int h=N;
        int hCnt = 0;
        
        for(int i=N-1; i >= 0; i--) {
            //cout << "0"  << "\t" << h << "\t"  << hCnt << endl;
            int c = citations[i];
            if(c >= h) {
                hCnt++;
            }
            else {
                while(h != c) {
                    h--;
                    if(hCnt >= h) {
                        break;
                    }
                }
                if(h == c)
                    hCnt++;
            }
           
            if(hCnt >= h) {
                break;
            }
//            cout << "1"  << "\t" << h << "\t"  << hCnt << endl;

            
        }
        return h;
    }
    
    int hIndex1(vector<int>& citations) {
        int N = citations.size();
        if(N == 0)
            return 0;
        vector<int> a(N+1, 0);
        
        // = i citations num
        for(int i=0; i < N;i++) {
            int c = citations[i];
            if(c <= N)
                a[c] ++;
        }
        
        //printVec(a);
        
        // < i citations num
        int sum =0;
        for(int i=0; i <= N; i++) {
            int oldSum = sum;
            sum += a[i];
            a[i] = oldSum;
        }
        
        //printVec(a);
        
        // citations num >= h
        int h=0;
        for(h=N; h >= 0; h--) {
            
            if((N-a[h]) >= h) {
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
    vector<int> v({0,1,3,5,6});

    int res = s.hIndex(v);
    cout << res << endl;

    return 0;
}


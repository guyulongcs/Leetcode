nclude <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1 = area(A, B, C, D);
        int a2 = area(E, F, G, H);
        int a3 = areaJoin(A, B, C, D, E, F, G, H);
        int a4 = a1 + a2 - a3;
        return a4;
        
    }
    
    int area(int A, int B, int C, int D) {
        int area = abs(C-A) * abs(D-B);
        return area;
    }
    
    int areaJoin(int A, int B, int C, int D, int E, int F, int G, int H) {
        int e1 =  edgeJoin(A, C, E, G);
        int e2 = edgeJoin(B, D, F, H);
        int area = e1 * e2;
        return area;
    }
    
    int edgeJoin(int l1, int h1, int l2, int h2) {
        int res = 0;
        int h=min(h1, h2);
        int l = max(l1, l2);
        if(h > l)
            res = h-l;
        return res;
    }
    
};


int main() {
    
    
    Solution s;
    
    int a[] = {0};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    
    //cout << v[0] << endl;
    
    int res=0;
    
    

    
    int i = 0;
    
    cout << res << endl;
    
    cout << endl;

    
    return 0;
}


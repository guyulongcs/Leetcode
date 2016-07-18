#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>


using namespace std;

class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(true) {
            if(i < 0 && j < 0)
                break;
            if(j < 0 || (j >=0 && i >= 0 && nums1[i] > nums2[j])) {
                nums1[k--] = nums1[i--];
            }
            else if (j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
        for(i=0; i < m+n; i++) {
            nums1[i] = nums1[i+k+1];
        }
    }
    
    void printVV(vector<vector<int>> & vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
    
    void printV(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
};



int main() {

    Solution s;
    vector<int> v1(10, 0);
    v1[0]=1;
    v1[1]=4;
    v1[2]=5;
    
  
    vector<int> v2({2,3,6,7});

    s.printV(v1);
    s.printV(v2);
    
    s.merge(v1, 3, v2,4);
    
    s.printV(v1);
    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = (int)nums1.size();
        int N2 = (int)nums2.size();
        int N = N1 + N2;
        double res=0;
        
        if(N % 2 == 0) {
            double res1 = findSortedArraysKth(nums1, N1, 0, nums2, N2, 0, N/2);
            double res2 = findSortedArraysKth(nums1, N1, 0, nums2, N2, 0, N/2+1);
            res = ( res1 + res2 ) / 2;
        }
        else {
            res = findSortedArraysKth(nums1, N1, 0, nums2, N2, 0, N/2+1);
        }
        
        return res;
    }
    
    double findSortedArraysKth(vector<int>& nums1, int N1, int s1, vector<int>& nums2, int N2, int s2, int k) {
        double res=0;
        
        if(N1-s1 > N2-s2) {
            return findSortedArraysKth(nums2, N2, s2, nums1, N1, s1, k);
        }
        
        if(N1-s1 == 0) {
            return nums2[s2+k-1];
        }
        
        if(k == 1) {
            return min(nums1[s1], nums2[s2]);
        }
        
        int p=min(k/2, N1);
        int q=k-p;
        
        if(nums1[s1+p-1] < nums2[s2+q-1]) {
            return findSortedArraysKth(nums1, N1, s1+p, nums2, N2, s2, k-p);
        }
        else if(nums1[s1+p-1] > nums2[s2+q-1]) {
            return findSortedArraysKth(nums1, N1, s1, nums2, N2, s2+q, k-q);
        }
        else {
            return nums1[s1+p-1];
        }
        
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v1;
    vector<int> v2;
    double res=0;
    
    v1 = vector<int>({101});
    v2 = vector<int>({100});
    res = s.findMedianSortedArrays(v1, v2);
    cout << res << endl;
    
    
    return 0;
}


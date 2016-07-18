#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int s1=0;
        int s2=0;
        
        int N1 = (int)nums1.size();
        int N2 = (int)nums2.size();
        

        for(int i=0; i <= k && i <= N1; i++) {
            if(k-i > N2) {
                continue;
            }
//            cout << "i, k-i:" << i << "\t" << k-i << endl;
            vector<int> arr1 = getVecMaxSubArray(nums1, N1, i);
            vector<int> arr2 = getVecMaxSubArray(nums2, N2, k-i);
            
            vector<int> merge = getVecMaxMerge(arr1, arr2, i, k-i);
//            printV(arr1);
//            printV(arr2);
//            printV(merge);
            getMaxVec(merge, res, res);
        }
     

        return res;
    }
    
    
    
    vector<int> getVecMaxSubArray(vector<int>& nums1, int N1, int k) {
        vector<int> res;
        int del=N1-k;
        for(int i=0; i < N1; i++) {
            while(del && res.size() && nums1[i] > res.back()) {
                res.pop_back();
                del--;
            }
            res.push_back(nums1[i]);
        }
        res.resize(k);
        return res;
    }
    
    bool isGreater(vector<int>& nums1, vector<int>& nums2, int N1, int N2, int i, int j) {
        while(i < N1 && j < N2 && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return (j == N2 || ((i < N1) && nums1[i] > nums2[j]));
    }
    vector<int> getVecMaxMerge(vector<int>& nums1, vector<int>& nums2, int N1, int N2) {
        vector<int> res;
        int i=0;
        int j=0;
        while(i < N1 || j < N2) {
            if(i == N1) {
                res.push_back(nums2[j++]);
            }
            else if(j == N2) {
                res.push_back(nums1[i++]);
            }
            else {
                if(isGreater(nums1, nums2, N1, N2, i, j)) {
                    res.push_back(nums1[i++]);
                }
                else {
                    res.push_back(nums2[j++]);
                }
            }
        }
        return res;
    }

    
    void getMaxVec(vector<int> & v1, vector<int> & v2, vector<int> & v) {
//        cout << "\ngetMaxVec" << endl;
       
        bool flagFirst = true;
        for(int i=0; i < v1.size() && i < v2.size(); i++) {
            if(v1[i] > v2[i]) {
                break;
            }
            if(v1[i] < v2[i]) {
                flagFirst = false;
                break;
            }
        }
        if(flagFirst)
            v = v1;
        else
            v = v2;
        
//        cout << "v1:";
//        printV(v1);
//        cout << "v2:";
//        printV(v2);
//        cout << "v:";
//        printV(v);
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
    
    vector<int> res;
    
    vector<int> v1;
    vector<int> v2;
    int k;
    
//    //test1
//    v1 = vector<int>({3,4,6,5});
//    v2 = vector<int>({9,1,2,5,8,3});
//    k = 5;
//    res = s.maxNumber(v1, v2, k);
//    s.printV(res);
//
//    //test2
//    v1 = vector<int>({6,7});
//    v2 = vector<int>({6,0,4});
//    k = 5;
//    res = s.maxNumber(v1, v2, k);
//    s.printV(res);
////
//    //test4
//    v1 = vector<int>({3,9});
//    v2 = vector<int>({8,9});
//    k = 3;
//    res = s.maxNumber(v1, v2, k);
//    s.printV(res);
////
////    //test3
//    v1 = vector<int>({6,0});
//    v2 = vector<int>({6,7,4});
//    k = 5;
//    res = s.maxNumber(v1, v2, k);
//    s.printV(res);
    
    
    //test3
    v1 = vector<int>({8,6,9});
    v2 = vector<int>({1,7,5});
    k = 3;
    res = s.maxNumber(v1, v2, k);
    s.printV(res);
    
    //test5
//    v1 = vector<int>({8,0,4,4,1,7,3,6,5,9,3,6,6,0,2,5,1,7,7,7,8,7,1,4,4,5,4,8,7,6,2,2,9,4,7,5,6,2,2,8,4,6,0,4,7,8,9,1,7,0});
//    v2 = vector<int>({6,9,8,1,1,5,7,3,1,3,3,4,9,2,8,0,6,9,3,3,7,8,3,4,2,4,7,4,5,7,7,2,5,6,3,6,7,0,3,5,3,2,8,1,6,6,1,0,8,4});
//    k = 50;
//    res = s.maxNumber(v1, v2, k);
//    s.printV(res);

    

    
    return 0;
}


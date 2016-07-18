#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

struct Bucket {
    int bmin;
    int bmax;
    int bcnt;
    Bucket() {
        bmin = 0;
        bmax = 0;
        bcnt = 0;
    }
};

class Solution {
public:
    int maximumGap(vector<int>& a) {
        int res ;
        int N = a.size();
        //res = maximumGap_sort(a);
        //res = maximumGap_part(a, 0, N-1);
        res = maximumGap_bucketSort(a);
        return res;
    }
    int maximumGap_bucketSort(vector<int>& a) {
        int n = (int)a.size();
        
        if(n < 2)
            return 0;
        
        int res = 0;
        
       

        vector<Bucket> bucketVec;
        bucketSort(a, bucketVec);
        res = getMaxGapFromBucket(bucketVec);
        
        
        return res;
        
    }
                   
    void bucketSort(vector<int>& a, vector<Bucket> & bucketVec) {
       
       int nmin, nmax;
       int n = (int)a.size();
       if(n < 2)
           return;
       getVecMinMax(a, nmin, nmax);
    
        if(nmin == nmax) {
            return;
            
        }
        
       int bucketCap = (int)(ceil( (double)(nmax-nmin) / (n-1) ));
    
       
        
       int bucketCnt = (nmax-nmin) / bucketCap + 1;
       //cout << "bucket:" << bucketCap << "\t" << bucketCnt << endl;
       bucketVec = vector<Bucket>(bucketCnt, Bucket());
       
       for(int i=0; i < n; i++) {
           int num = a[i];
           int loc = (num-nmin) / bucketCap;
           if(bucketVec[loc].bcnt == 0) {
               bucketVec[loc].bmin = num;
               bucketVec[loc].bmax = num;
           }
           else {
               bucketVec[loc].bmin = min(bucketVec[loc].bmin, num);
               bucketVec[loc].bmax = max(bucketVec[loc].bmax, num);
           }
           bucketVec[loc].bcnt++;
       }
    }
    
    int getMaxGapFromBucket(vector<Bucket> & bucketVec) {
        int pre=-1;
        int res=0;
        for(int i=0; i < bucketVec.size(); i++) {
            if(bucketVec[i].bcnt > 0) {
                if(pre < 0) {
                    pre = i;
                }
                else {
                    int cur = bucketVec[i].bmin - bucketVec[pre].bmax;
                    pre = i;
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
    
    
    
    void getVecMinMax(vector<int>& a, int & nmin, int & nmax) {
        nmin = INT32_MAX;
        nmax = INT32_MIN;
        for(int i=0; i < a.size(); i++) {
            nmin = min(nmin, a[i]);
            nmax = max(nmax, a[i]);
        }
    }
    
    int maximumGap_sort(vector<int>& a) {
        int n = a.size();
        if(n < 2)
            return 0;
        
        sort(a.begin(), a.end());
        int maxDiff=INT32_MIN;
        int diff;
        
        for(int i=1; i < n; i++) {
            int diff = a[i] - a[i-1];
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
    
    int maximumGap_part(vector<int>& a, int s, int e) {
        int n = e-s+1;
        if(n < 2)
            return 0;
        
        int p = partition(a, s, e);
        //cout << "s, e, p:" << s << "\t" << e << "\t" << p << endl;
        
        int left = maximumGap_part(a, s, p-1);
        int right = maximumGap_part(a, p+1, e);
        int maxNum = max(left, right);
        int num;
        if(p-1 >= s) {
            num = a[p] - a[p-1];
            maxNum = max(maxNum, num);
        }
        if(p+1 <= e) {
            num = a[p+1] - a[p];
            maxNum = max(maxNum, num);
        }
        return maxNum;
    }
    
    int partition(vector<int>& a, int s, int e) {
        int num = a[s];
        int i=s;
        int j=e;
        while(true) {
            while(i <= e && a[i] <= num) {
                i++;
            }
            while(j>= s && a[j] > num) {
                j--;
            }
            if(i > j)
                break;
            swap(a[i], a[j]);
        }
        swap(a[j], a[s]);
        int p = j;
        return p;
    }
};

int main() {
    Solution s= Solution();

    
    vector<int> v({1,1,1,1});
    int res = s.maximumGap(v);
    cout << res << endl;
    return 0;
}



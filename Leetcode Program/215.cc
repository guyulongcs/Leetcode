#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int res =0;
        //res = findKthLargestSort(nums, k);
        //res = findKthLargestPartition(nums, k);
        //res = findKthLargestPriQueue(nums, k);
        res = findKthLargestHeap(nums, k);
        
        return res;
    }
    
    int findKthLargestSort(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int res = nums[N-k];
        return res;
    }
    
    
    int findKthLargestPartition(vector<int>& nums, int k) {
        
        int N = nums.size();
        int m = N-k+1;
        int res = findKthLargestPartitioVec(nums, 0, N-1, m);
        return res;
    }
    
    
    int findKthLargestPartitioVec(vector<int>& nums, int s, int e, int m) {
        if(nums.size() == 0)
            return 0;
       
        int p = partition(nums, s, e);
        int cnt = p - s+1;
        
        if(m == cnt) {
            return nums[p];
        }
        else if(m < cnt) {
            return findKthLargestPartitioVec(nums, s, p, m);
        }
        else {
            return findKthLargestPartitioVec(nums, p+1, e, m-cnt);
        }
        
    }
    
    void printVec(vector<int>& nums, int start, int end) {
        for(int i=start; i <= end; i++) {
            cout << nums[i] << "\t";
        }
        cout << endl;
    }
    
    int partition(vector<int>& nums, int start, int end) {
        
        
        int a = nums[start];
        int b = start;
        int e = end;
        while(true) {
            while(b < end && nums[b] <= a)
                b++;
            while(e > start && nums[e] >= a)
                e--;
            if(b >= e)
                break;
            swap(nums[b], nums[e]);
        }
        swap(nums[e], nums[start]);
        int p =e;
        return p;
    }
    
    int findKthLargestPriQueue(vector<int>& nums, int k) {
        int N = nums.size();
        int res = 0;
        
        k = min(k, N);
        
        //greater: minimum heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i < k;i++) {
            pq.push(nums[i]);
        }
        //cout << "top:" << pq.top() << endl;
        
        for(int i=k; i < N; i++) {
            int t = pq.top();
            if( t < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        res = pq.top();
        
        return res;
    }
    
    int findKthLargestHeap(vector<int>& nums, int k) {
        int N = nums.size();
        int res = 0;
        
        k = min(k, N);
        
        
        vector<int> v(k, 0);
        for(int i=0; i < N; i++) {
            int num = nums[i];
//            cout << endl << "i:" << i << endl;


            if(i < k) {
                v[i] = num;
            }
            if(i == k-1) {
                make_heap(v.begin(), v.end(), greater<int>());
            }
            if(i >= k) {
                if(num > v[0]) {
                    v[0] = num;
                    
                    make_heap(v.begin(), v.begin()+k, greater<int>());
                    
//                    pop_heap(v.begin(), v.end(), greater<int>());
//                    v.pop_back();
//                    v.push_back(num);
//                    push_heap(v.begin(), v.end(), greater<int>());
                    
                }
            }
//            printVec(v, 0, v.size()-1);

        }
        res = v[0];
        
        return res;
    }
};

int main() {
    Solution s= Solution();
    
    int k=0;
    vector<int> v1({3,1,2});
    
    int N = v1.size();
    for(k=1; k <= 3; k++) {
  
        int res = s.findKthLargest(v1,k);
        cout << "k:" << k << ", " << res << endl;
    }
    
    return 0;
}


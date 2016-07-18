#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        
        int N = a.size();
        
        k=min(k, N);
        vector<int> res;
        
        if(N==0) {
            return res;
        }
        
        deque<int> q;
        
        vector<int> b;
        for(int i=0; i < k; i++) {
            while(!q.empty() && a[i] >= a[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        
        for(int i=k; i < N; i++) {
            b.push_back(a[q.front()]);
            while(!q.empty() && a[i] > a[q.back()])
                q.pop_back();

            while(!q.empty() && (i-k >= q.front()))
                q.pop_front();

            
            q.push_back(i);
        }
        b.push_back(a[q.front()]);

        
        return b;
    }
};

void printVector(vector<int> v) {
    for(int i=0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
}

int main() {
    Solution s= Solution();

    int k=0;
    vector<int> v1({1,3,1,2,0,5});


   
    int N = v1.size();
    int K = 3;
    for(k=K; k <= K; k++) {

        vector<int> res = s.maxSlidingWindow(v1,k);
        printVector(res);
    }

    return 0;
}



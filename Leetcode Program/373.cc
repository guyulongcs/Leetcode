nclude <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <cstdlib>

using namespace std;

struct Node {
    pair<int, int> p;
    int val;
    Node() {}
    Node(int f=0, int s=0, int v=0): p(pair<int, int>(f, s)), val(v){}
    
    friend bool operator < (const Node & n1, const Node & n2) {
        return n1.val < n2.val;
    }
    
    friend bool operator > (const Node & n1, const Node & n2) {
        return n1.val > n2.val;
    }
};
                                       
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        if(k == 0) {
            return res;
        }
        
        int m = nums1.size();
        int n = nums2.size();
        
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                if(i + j <= k) {
                    int val = nums1[i] + nums2[j];
                    Node node(nums1[i], nums2[j], val);
//                    cout << "val:" << val << endl;
                    pq.push(node);
                }
            }
        }
        
        for(int i=0; i < k; i++) {
            if(pq.empty()) {
                break;
            }
            Node node = pq.top();
            pq.pop();
//            cout << "node:" << node.val << endl;
            res.push_back(node.p);
        }
        return res;
    }
    
    void printVP(vector<pair<int, int>> & v) {
        for(int i=0; i < v.size(); i++) {
            pair<int, int> p=v[i];
            cout << "[" << p.first << "," << p.second << "]" << "\t";

        }
        cout << endl;
    }
};


int main() {
    Solution sol = Solution();
    
    vector<int> v1;
    vector<int> v2;
    int k;
    vector<pair<int, int>> res;
    
    
    v1 = {1, 7, 11};
    v2 = {2, 4, 6};
    k = 3;
    res = sol.kSmallestPairs(v1, v2, k);
    sol.printVP(res);
    
    v1 = {1, 1, 2};
    v2 = {1, 2, 3};
    k = 2;
    res = sol.kSmallestPairs(v1, v2, k);
    sol.printVP(res);
    
    v1 = {1, 2};
    v2 = {3};
    k = 3;
    res = sol.kSmallestPairs(v1, v2, k);
    sol.printVP(res);
    
    
    return 0;
}

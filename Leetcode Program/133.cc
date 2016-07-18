#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    
    UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode * g=NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> dp;
        g = dfs(node, dp);
        return g;
        
    }
    
    UndirectedGraphNode * dfs(UndirectedGraphNode * node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& dp) {
        if(node == NULL)
            return NULL;
        if(dp.find(node) != dp.end()) {
            return dp[node];
        }
        
        UndirectedGraphNode * n = new UndirectedGraphNode(node->label);
        for(int i=0; i < (node->neighbors).size(); i++) {
            UndirectedGraphNode * nei = (node->neighbors)[i];
            UndirectedGraphNode * neiNew = n;
            if(nei != node) {
              neiNew = dfs(nei, dp);
            }
            (n->neighbors).push_back(neiNew);
        }
        dp[node] = n;
        return n;
    }
    
};


int main() {

    Solution s;
    UndirectedGraphNode * g = new UndirectedGraphNode(3);
    (g->neighbors) = vector<UndirectedGraphNode *>(2, NULL);
    (g->neighbors)[0] =new UndirectedGraphNode(1);
    (g->neighbors)[1] =new UndirectedGraphNode(2);
    UndirectedGraphNode * p1 = (g->neighbors)[0];
    (p1->neighbors)= vector<UndirectedGraphNode *>(1, NULL);
    (p1->neighbors)[0] = new UndirectedGraphNode(2);
    UndirectedGraphNode * p2 =(p1->neighbors)[0];
    p2->neighbors = vector<UndirectedGraphNode *>(1, NULL);
    (p2->neighbors)[0] = p2;
    
    cout << (g->neighbors)[1]->label << endl;
    //return 0;
    UndirectedGraphNode * gn = s.cloneGraph(g);
    cout << (gn->neighbors)[1]->label << endl;
    
    return 0;
}


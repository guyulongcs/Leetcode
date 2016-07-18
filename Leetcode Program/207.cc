nclude <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;

const int WHITE=0;
const int GRAY=1;
const int BLACK=2;

class Graph {
    int N;
    vector< vector<int> > adj;
public:
    Graph() {
        N=0;
    }
    Graph(int n, vector< pair<int, int> >& edges) {
        vector<int> v;
        N=n;
        adj =vector< vector<int> >(N, v);
        for(int i=0; i < edges.size(); i++) {
            pair<int, int> p = edges[i];
            int ns = p.first;
            int ne = p.second;
            (adj[ne]).push_back(ns);
        }
    }
    
    bool hasCycle() {
        bool flag = false;
        vector<int> flagVisit(N, WHITE);
        
        for(int i=0; i < N; i++) {
            dfs_visit(i, flagVisit, flag);
            if(flag)
                break;
        }
        
//        cout << "hasCycle:" << flag << endl;
        return flag;
    }
    
    void dfs_visit(int node, vector<int> & flagVisit, bool& flagCycle) {
        if(flagCycle)
            return;
        if(flagVisit[node] == BLACK) {
            return;
        }
        flagVisit[node] = GRAY;
        
        for(int i=0; i < adj[node].size(); i++) {
            int nodeAdj = adj[node][i];
            if(flagVisit[nodeAdj] == WHITE) {
                dfs_visit(nodeAdj, flagVisit, flagCycle);
            }
            else if(flagVisit[nodeAdj] == GRAY) {
                flagCycle = true;
            }
            if(flagCycle) {
                break;
            }
        }
        flagVisit[node] = BLACK;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g = Graph(numCourses, prerequisites);
        bool flag = !(g.hasCycle());
        return flag;
    }

};

int main() {

    Solution s;

    vector<pair<int, int>> p;
    p.push_back(pair<int,int>(1,0));
    p.push_back(pair<int,int>(0,1));

    bool res = s.canFinish(2, p);
    cout << res << endl;

    return 0;
}

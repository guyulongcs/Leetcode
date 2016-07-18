#include <iostream>
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


struct QueueNode {
    int id;
    int val;
    QueueNode(int i=0, int v=0):id(i), val(v) {}
    
    friend bool operator < (const QueueNode & q1, const QueueNode & q2) {
        return q1.val < q2.val;
    }
};

class Graph {
    int N;
    vector< vector<int> > adj;
public:
    Graph() {
        N=0;
    }
    Graph(int n, vector< pair<int, int> >& edges) {
       
        N=n;
        adj =vector< vector<int> >(N, vector<int>());
        for(int i=0; i < edges.size(); i++) {
            pair<int, int> p = edges[i];
            int ns = p.first;
            int ne = p.second;
            (adj[ne]).push_back(ns);
        }
        
//        for(int i=0; i < N; i++) {
//            cout << "i:" << i << ",:" << adj[i].size() << endl;
//        }
    }
    
    bool hasCycle() {
        bool flag = false;
        vector<int> flagVisit(N, WHITE);
        
        for(int i=0; i < N; i++) {
            dfs_visit_cycle(i, flagVisit, flag);
            if(flag)
                break;
        }
        
//        cout << "hasCycle:" << flag << endl;
        return flag;
    }
    
    
    
    void dfs_visit_cycle(int node, vector<int> & flagVisit, bool& flagCycle) {
        if(flagCycle)
            return;
        if(flagVisit[node] == BLACK) {
            return;
        }
        flagVisit[node] = GRAY;
        
        for(int i=0; i < adj[node].size(); i++) {
            int nodeAdj = adj[node][i];
            if(flagVisit[nodeAdj] == WHITE) {
                dfs_visit_cycle(nodeAdj, flagVisit, flagCycle);
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
    
    void dfs_visit(int node, vector<int> & flagVisit, vector<int> & vs, vector<int> & ve, int & t, bool & flagCycle) {
        if(flagVisit[node] == BLACK) {
            return;
        }
        
//        cout << endl << "dfs_visit node:" << node << endl;

        
        flagVisit[node] = GRAY;
        vs[node] = t++;
        
//        cout << "adj[node].size():" << adj[node].size() << endl;
        for(int i=0; i < adj[node].size(); i++) {
//            cout << "i:" << i << endl;
            int nodeAdj = adj[node][i];
//            cout << "nodeAdj:" << nodeAdj << endl;

            if(flagVisit[nodeAdj] == WHITE) {
                dfs_visit(nodeAdj, flagVisit, vs, ve, t, flagCycle);
            }
            else if(flagVisit[nodeAdj] == GRAY) {
                flagCycle = true;
                break;
            }
        }
        flagVisit[node] = BLACK;
        ve[node] = t++;
    }

    
    vector<int> topoSort() {
        vector<int> flagVisit(N, WHITE);
        vector<int> vs(N, 0);
        vector<int> ve(N, 0);
        vector<int> res;

        
        bool flagCycle = false;
        int t=1;
        for(int i=0; !flagCycle && i < N; i++) {
            if(flagVisit[i] == WHITE)
                dfs_visit(i, flagVisit, vs, ve, t, flagCycle);
        }
        if(flagCycle) {
            return res;
        }
        
//        cout << "ve:" << endl;
//        printVector(ve);
        
        priority_queue<QueueNode, vector<QueueNode>, less<QueueNode> > pq;
        for(int i=0; i < ve.size(); i++) {
            QueueNode node = QueueNode(i, ve[i]);
            pq.push(node);
        }
        
        while(!pq.empty()) {
            QueueNode node = pq.top();
            res.push_back(node.id);
            pq.pop();
        }
        return res;
    }
    
    void printVector(vector<int> v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g = Graph(numCourses, prerequisites);
        bool flag = !(g.hasCycle());
        return flag;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g = Graph(numCourses, prerequisites);
        vector<int> s= g.topoSort();
        return s;
    }

    void printVector(vector<int> v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }

};

int main() {

    Solution s;

    vector<pair<int, int>> p;
    p.push_back(pair<int,int>(0,1));
    p.push_back(pair<int,int>(1,2));
//    p.push_back(pair<int,int>(1,0));

    vector<int> res = s.findOrder(3, p);
    s.printVector(res);

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;


class Graph {
    int N;
    vector< set<int> > adj;
public:
    Graph() {};
    Graph(int n, vector<pair<int, int>>& edges) {
        N = n;
        adj = vector< set<int> >(N, set<int>());
        for(int i=0; i < edges.size(); i++) {
            int f = edges[i].first;
            int s = edges[i].second;
            adj[f].insert(s);
            adj[s].insert(f);
        }
    }
    
    vector<int> findMinHeightTrees() {
        vector<int> d(N, 0);
        
        set<int> s;
        
        
        //getGraphNodeDegree(d, s);
        set<int> leaves;
        for(int i=0; i < N; i++) {
            if(adj[i].size() == 1) {
                leaves.insert(i);
            }
        }
       
        int n = N;
        while(n > 2) {
            set<int> nleaves;
            for(auto it = leaves.begin(); it != leaves.end(); it++) {
                int n = *it;
                int nadj = *adj[n].begin();
                adj[nadj].erase(n);
                if(adj[nadj].size() == 1) {
                    nleaves.insert(nadj);
                }
            }
            n -= leaves.size();
            leaves = nleaves;
        }
        
        vector<int> v;
        for(auto it = leaves.begin(); it != leaves.end(); it++) {
            v.push_back(*it);
        }
        return v;
    }
    
    void getGraphNodeDegree(vector<int> & d, set<int> &s) {
        for(auto it=s.begin(); it != s.end(); it++) {
            d[*it] = adj[*it].size();
        }
    }

};


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> v;
        
        if(edges.size() == 0) {
            v.push_back(0);
            return v;
        }
        Graph g(n, edges);
        v = g.findMinHeightTrees();
        return v;
    }
    
    void printV(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
};



int main() {
    Solution s= Solution();
    int n=3;
    vector<pair<int, int>> v;
    v.push_back(pair<int,int>(0,1));
    v.push_back(pair<int,int>(0,2));
//    v.push_back(pair<int,int>(2,3));
//    v.push_back(pair<int,int>(4,3));
//    v.push_back(pair<int,int>(5,4));
    
    vector<int> res = s.findMinHeightTrees(n, v);
    
    s.printV(res);
    
    return 0;
}


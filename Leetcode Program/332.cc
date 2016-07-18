#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class EdgeNode {
public:
    int edgeId;
    int nodeId;
    
    EdgeNode(int e=0, int n=0): edgeId(e), nodeId(n){}
};

class QueueNode {
public:
    EdgeNode edgeNode;
    string s;

    QueueNode(EdgeNode en, string str= ""): edgeNode(en), s(str){}
    
    friend bool operator > (QueueNode qn1, QueueNode qn2) {
        return qn1.s > qn2.s;
    }
};
class Graph {

    int N;
    int E;
    unordered_map<string, int> mapNodeId;
    unordered_map<int, string> mapIdNode;
    unordered_map<int, vector<EdgeNode> > adj;
public:
    Graph() {
        N=0;
        E=0;
    }

    Graph(vector< pair<string, string> > tickets) {
//        cout << "create graph" << endl;
        int edgeId=0;
        int nodeId = 0;
        for(int i=0; i < tickets.size(); i++)  {
            string from = tickets[i].first;
            string to = tickets[i].second;
//            cout << "from, to:" << from << "\t" << to << endl;
            if(mapNodeId.find(from) == mapNodeId.end()) {
                mapNodeId[from] = nodeId++;
            }
            if(mapNodeId.find(to) == mapNodeId.end()) {
                mapNodeId[to] = nodeId++;
            }
            
            int ifrom = mapNodeId[from];
            int ito = mapNodeId[to];
            
            if(adj.find(ifrom) == adj.end()) {
                adj[ifrom] = vector<EdgeNode>();
            }
            (adj[ifrom]).push_back(EdgeNode(edgeId++, ito));
        }
        
        for(unordered_map<string, int>::iterator it = mapNodeId.begin(); it != mapNodeId.end(); it++) {
            mapIdNode[it->second] = it->first;
        }
        
        N = (int)adj.size();
        E = edgeId;
//        cout << "N:" << N << endl;
//        cout << "E:" << E << endl;
    }
    
    void printGraph() {
        for(unordered_map<string, int>::iterator it = mapNodeId.begin(); it != mapNodeId.end(); it++) {
            cout << it->first << "\t" << it->second << endl;
        }
        cout << endl;
        
       
        cout << "adj" << endl;
        for(unordered_map<int, vector<EdgeNode> >::iterator it = adj.begin(); it != adj.end(); it++) {
            int nid = it->first;
            cout << nid  << "\tedges:";
            for(int i=0; i < it->second.size(); i++) {
                EdgeNode edgeNode = (it->second)[i];
                cout << "(" << edgeNode.edgeId<< ":" << edgeNode.nodeId << ")\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    vector<string> traverse(string s="JFK") {
        vector<string> res;
        
        int sid = mapNodeId[s];
        
        dfs(sid, res);

        return res;
    }

    void dfs(int s, vector<string>& res) {
        
        unordered_map<int, bool> visitEdges;
        

        for(int i=0; i < E; i++) {
            visitEdges[i] = false;
        }
        
        
        vector<int> path;
        int plen=0;
        int pmax = E;
        
        path.push_back(s);
        
        bool flagFind = false;
        dfs_visit(s, path, plen, pmax, res, visitEdges, flagFind);
    }

    void dfs_visit(int s, vector<int> & path, int pln, int pmax, vector<string>& res, unordered_map<int,  bool>& visitEdges, bool & flagFind){
        
        if(pln == pmax) {
            getMaxPathStr(res, path);
            flagFind = true;
            return;
        }
        
        if(adj.find(s) != adj.end()) {
            priority_queue< QueueNode, vector<QueueNode>, greater<QueueNode> > pq;
            for(int i=0; i < adj[s].size(); i++) {

                EdgeNode edgeNode = adj[s][i];
                
                int edge = edgeNode.edgeId;
                bool fEdge = visitEdges[edge];
                int to = edgeNode.nodeId;
               
                
                if(fEdge == false) {
                    pq.push(QueueNode(edgeNode, mapIdNode[to]));
                }
            }
            
            while(!pq.empty() ) {
                QueueNode queueNode = pq.top();
                EdgeNode edgeNode = queueNode.edgeNode;
                int edge = edgeNode.edgeId;
                int to = edgeNode.nodeId;
                visitEdges[edge] = true;
                path.push_back(to);
                dfs_visit(to, path, pln+1, pmax, res, visitEdges, flagFind);
                visitEdges[edge] = false;
                path.erase(path.begin() + path.size()-1);
                pq.pop();
                if(flagFind) {
                    break;
                }

            }
            
        }
        
    }
    
    void getMaxPathStr(vector<string> & res, vector<int> v) {
        vector<string> vs = getPathStr(v);
        getMax(res, vs);
    }
    
    vector<string> getPathStr(vector<int> v) {
        vector<string> res;
        for(int i=0; i < v.size(); i++) {
            res.push_back(mapIdNode[v[i]]);
        }
        return res;
    }
    
    
    void getMax(vector<string>& res, vector<string> v){
        if(res.size() == 0) {
            res = v;
            return;
        }
        bool flagUpdate = false;
        for(int i=0; i < v.size(); i++) {
            if(v[i] < res[i]) {
               // cout << v[i] << "<" << res[i] << endl;
                flagUpdate = true;
                break;
            }
            if(v[i] > res[i]) {
                break;
            }
        }
        if(flagUpdate) {
            res = vector<string>(v);
        }

    }
    
//    void printVS(vector<string> v) {
//        for(int i=0; i < v.size(); i++) {
//            cout << v[i] << "\t";
//        }
//        cout << endl;
//    }
//    
//    void printV(vector<int> v) {
//        for(int i=0; i < v.size(); i++) {
//            cout << v[i] << "\t";
//        }
//        cout << endl;
//    }
    
};

class Solution {
public:
    
    vector<string> findItinerary(vector< pair<string, string> > tickets) {
        Graph g = Graph(tickets);
        vector<string> res;
        //g.printGraph();
        res = g.traverse();
        return res;
    }
    
    static void printVS(vector<string> v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
};


int main() {

    Solution s;
    vector<pair<string, string>> tickets;
    
    //test1
    tickets.push_back(pair<string, string>("MUC", "LHR"));
    tickets.push_back(pair<string, string>("JFK", "MUC"));
    tickets.push_back(pair<string, string>("SFO", "SJC"));
    tickets.push_back(pair<string, string>("LHR", "SFO"));
    
    
    //test2
//    tickets.push_back(pair<string, string>("JFK","SFO"));
//    tickets.push_back(pair<string, string>("JFK","ATL"));
//    tickets.push_back(pair<string, string>("SFO","ATL"));
//    tickets.push_back(pair<string, string>("ATL","JFK"));
//    tickets.push_back(pair<string, string>("ATL","SFO"));
//    
    

    
    vector<string> res = s.findItinerary(tickets);

//    cout << "res:" << endl;
   Solution::printVS(res);

    return 0;
}


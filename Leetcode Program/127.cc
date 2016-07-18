#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
    string s;
    int level;
public:
    Node() {}
    Node(string str="", int l=0): s(str), level(l){};
};

class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordSet) {
        int res=0;
        wordSet.insert(beginWord);
        wordSet.insert(endWord);
        res=ladderLengthBfs(beginWord, endWord, wordSet);
        return res;
    }
    
    int ladderLengthBfs(string beginWord, string endWord, unordered_set<string>& wordSet) {
        int res=0;
        
        //res = bfs_graph(wordSet, beginWord, endWord);
        res = bfs(wordSet, beginWord, endWord);
        
        return res;
    }
    
    void createGraph(unordered_set<string>& wordSet, int N, unordered_map<int, string> & wordMapIntStr, unordered_map<string, vector<string>> & g) {
        for(int i=0; i < N; i++) {
            string w1 = wordMapIntStr[i];
            for(int j=i; j < N; j++) {
                string w2 = wordMapIntStr[j];
                if(calStrDis(w1, w2) == 1) {
//                    cout << "w1, w2:" << w1 << "\t" << w2 << endl;
                    g[w1].push_back(w2);
                    g[w2].push_back(w1);
                }
            }
                
        }
    }
    
    int bfs(unordered_set<string>& wordSet, string beginWord, string endWord) {
        int res=0;
        queue<Node> q;
        q.push(Node(beginWord, 0));
        
        int level = 0;
        bool flag = false;
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while(!q.empty() && !flag) {
            Node node = q.front();
            string w = node.s;
            int curLevel = node.level;
            q.pop();
            
            int wlen = (int)w.length();
            for(int i=0; i < wlen && !flag; i++) {
                string wnext = w;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    wnext[i] = ch;
                    if(wnext == w) {
                        continue;
                    }
                    
                    if(wordSet.find(wnext) != wordSet.end()) {
                        if(wnext == endWord) {
                            level = curLevel;
                            flag = true;
                            break;
                        }
                        if(visited.find(wnext) == visited.end()) {
                            q.push(Node(wnext, curLevel+1));
                            visited.insert(wnext);
                        }
                    }
                    
                    
                }
            }
        }
        if(flag) {
            res = level + 2;
        }
        else {
            res = 0;
        }
        //        cout << "bfs res:" << res << endl;
        return res;
    }
    
    void create_graph(unordered_set<string>& wordSet, unordered_map<string, vector<string>> & g) {
        int N = (int)wordSet.size();
        //wordMap
        unordered_map<string, int> wordMap;
        unordered_map<int, string> wordMapIntStr;
        getWordMap(wordSet, wordMap, wordMapIntStr);
        
        
        createGraph(wordSet, N, wordMapIntStr, g);
    }
    int bfs_graph(unordered_set<string>& wordSet, string beginWord, string endWord) {
        unordered_map<string, vector<string>> g;
        create_graph(wordSet, g);
    

        
        int res=0;
        queue<Node> q;
        q.push(Node(beginWord, 0));
        
        int level = 0;
        bool flag = false;
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while(!q.empty() && !flag) {
            Node node = q.front();
            string w = node.s;
            int curLevel = node.level;
            q.pop();
            
            for(int i=0; i < g[w].size(); i++) {
                string w2 = g[w][i];

                if(w2 == endWord) {
                    level = curLevel;
                    flag = true;
                    break;
                }
                if(visited.find(w2) == visited.end()) {
                    q.push(Node(w2, curLevel+1));
                    visited.insert(w2);
                }
            }
            
        }
        if(flag) {
            res = level + 2;
        }
        else {
            res = 0;
        }
//        cout << "bfs res:" << res << endl;
        return res;
    }
    
    
    void printWords(int N,  unordered_map<int, string> & wordMapIntStr) {
        cout << "\nwords:" << endl;
        for(int i=0; i < N; i++) {
            string word = wordMapIntStr[i];
            cout << word << "\t";
        }
        cout << endl;
    }

    int calStrDis(string & w1, string & w2) {
        int dis=0;
        if(w1.length() != w2.length())
            return 0;
        
        for(int i=0; i < w1.length(); i++) {
            if(w1[i] != w2[i])
                dis++;
        }
        
        return dis;
    }
    
    void getWordMap(unordered_set<string>& wordSet, unordered_map<string, int> & wordMap, unordered_map<int, string> & wordMapIntStr) {
        int id=0;
        for(unordered_set<string>::iterator it=wordSet.begin(); it != wordSet.end(); it++) {
            wordMap[*it] = id;
            wordMapIntStr[id] = *it;
            id++;
        }
    }
    
    void printSet(unordered_set<string> & wordSet) {
        for(unordered_set<string>::iterator it=wordSet.begin(); it != wordSet.end(); it++) {
            string w = *it;
            cout << w << "\t";
        }
        cout << endl;
    }

    void printVV(vector<vector<int>> & vv) {
        cout << endl;
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
    
    void printV(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t\t";
        }
        cout << endl;
    }
    
};


int main() {
    Solution sol;
    
    int res=0;
    
    string beginWord;
    string endWord;
    unordered_set<string> wordList;
    
    beginWord = "hit";
    endWord = "cog";
    wordList =unordered_set<string>({"hot","dot","dog","lot","log"});
    res = sol.ladderLength(beginWord, endWord, wordList);
    cout << res << endl;
    
    beginWord = "a";
    endWord = "c";
    wordList =unordered_set<string>({"a","b","c"});
    res = sol.ladderLength(beginWord, endWord, wordList);
    cout << res << endl;
    
      return 0;
}


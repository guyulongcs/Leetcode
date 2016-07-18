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
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordSet) {
        vector<vector<string>> res;
        wordSet.insert(beginWord);
        wordSet.insert(endWord);
        
        findLaddersBfs(beginWord, endWord, wordSet, res);
        return res;
    }
    
    
    void findLaddersBfs(string beginWord, string endWord, unordered_set<string>& wordSet, vector<vector<string>> & res) {
        bfs_find(wordSet, beginWord, endWord, res);
    }
    
    
    void bfs_find(unordered_set<string>& wordSet, string beginWord, string endWord, vector<vector<string>> & res) {
        
        queue<Node> q;
        q.push(Node(beginWord, 0));
        unordered_map<string, int> mapWordLevel;

        
        
        int level = 0;
        bool flag = false;
        
        int maxLevel = INT32_MAX;
        
        while(!q.empty()) {
            Node node = q.front();
            string w = node.s;
            int curLevel = node.level;
            q.pop();
            
            mapWordLevel[w]=curLevel;

            wordSet.erase(w);
            
            if(curLevel > maxLevel) {
                continue;
            }
            
//                        cout << "visit queue w:" << w << endl;
            int wlen = (int)w.length();
            for(int i=0; i < wlen; i++) {
                string wnext = w;
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(wnext[i] == ch) {
                        continue;
                    }
                    wnext[i] = ch;
                    
                    
                    if(wordSet.find(wnext) != wordSet.end()) {
//                        cout << "\twnext:" << wnext << endl;
                        if(mapWordLevel.count(wnext) > 0) {
                            continue;
                        }
                        mapWordLevel[wnext]=curLevel+1;
                        if(wnext == endWord) {
                            //level = curLevel;
                            flag = true;
                            maxLevel = min(maxLevel, curLevel+1);
                        }
                        else
                        {
                            q.push(Node(wnext, curLevel+1));
                        }
                    }
                }
            }
        }
        
        if(flag) {
            getPaths(mapWordLevel, wordSet, beginWord, endWord, maxLevel, res);
        }
    }
    
    void getPaths(unordered_map<string, int> & mapWordLevel, unordered_set<string>& wordSet, string beginWord, string endWord, int maxLevel, vector<vector<string>> & res) {
        dfs_path(mapWordLevel, wordSet, beginWord, endWord, maxLevel, res);
    }
    
    void dfs_path(unordered_map<string, int> & mapWordLevel, unordered_set<string>& wordSet, string beginWord, string endWord, int maxLevel, vector<vector<string>> & res) {
        vector<string> v;
        v.push_back(endWord);
        dfs(mapWordLevel, wordSet, beginWord, endWord, maxLevel, res, v);
    }
    
    
    void dfs(unordered_map<string, int> & mapWordLevel, unordered_set<string>& wordSet, string beginWord, string endWord, int maxLevel, vector<vector<string>> & res,  vector<string> & v) {
        //        v.push_back(endWord);
        if(maxLevel < -1)
            return;
        
        if(endWord == beginWord) {
            vector<string> curV = v;
            reverse(curV.begin(), curV.end());
            res.push_back(curV);
            return;
        }
        
        if(maxLevel > 0) {
            string w= endWord;
            int wlen = (int)w.length();
            for(int i=0; i < wlen; i++) {
                string wnext = w;
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(wnext[i] == ch) {
                        continue;
                    }
                    wnext[i] = ch;
                    
                    if(mapWordLevel.count(wnext) > 0 ) {
                        if(mapWordLevel[wnext]==maxLevel-1) {
                            v.push_back(wnext);
                            dfs(mapWordLevel, wordSet, beginWord, wnext, maxLevel-1, res, v);
                            v.pop_back();
                        }
                    }
                }
            }
        }

        
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
    
    void printVVStr(vector<vector<string>> & vv) {
        cout << endl;
        for(int i=0; i < vv.size(); i++) {
            printVStr(vv[i]);
        }
    }
    
    void printVStr(vector<string> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t\t";
        }
        cout << endl;
    }
    
};


int main() {
    Solution sol;

    vector<vector<string>> res;

    string beginWord;
    string endWord;
    unordered_set<string> wordList;

    beginWord = "hit";
    endWord = "cog";
    wordList =unordered_set<string>({"hot","dot","dog","lot","log"});
    res = sol.findLadders(beginWord, endWord, wordList);
    sol.printVVStr(res);

    return 0;
}


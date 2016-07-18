#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <ctime>
using namespace std;

const int LETTER_CNT=26;


class TrieNode {
public:
    bool hasWord;
    vector<TrieNode *> a;
public:
    // Initialize your data structure here.
    TrieNode() {
        hasWord = false;
        a = vector<TrieNode *>(LETTER_CNT, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        if(word.length() == 0)
            return;
        
        TrieNode * T =root;
        for(int i=0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if((T->a)[index] == NULL) {
                (T->a)[index] = new TrieNode();
            }
            T = (T->a)[index];
        }
        
        T->hasWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        bool flag = true;
        
        TrieNode * T =root;
        for(int i=0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(T == NULL || (T->a)[index] == NULL) {
                flag = false;
                break;
            }
            T = (T->a)[index];
        }
        if(flag && T->hasWord == true) {
            flag = true;
        }
        else {
            flag = false;
        }
        
        return flag;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        bool flag = true;
        
        TrieNode * T =root;
        for(int i=0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if(T == NULL || (T->a)[index] == NULL) {
                flag = false;
                break;
            }
            T = (T->a)[index];
        }
        
        return flag;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> v;
        
        //words = removeDuplicates(words);
        
        Trie trie = buildTrie(words);
       
        findWordsTrie(board, words, trie, v);
        
        v = removeDuplicates(v);
        
        return v;
    }
    
    Trie buildTrie(vector<string>& words) {
        Trie trie;
        for(int i=0; i < words.size(); i++) {
            trie.insert(words[i]);
        }
        return trie;
    }
    
    vector<string> removeDuplicates(vector<string>& words) {
        vector<string> res;
        set<string> wordSet;
        for(int i=0; i < words.size(); i++) {
            wordSet.insert(words[i]);
        }
        res= vector<string>(wordSet.begin(), wordSet.end());
        return res;
    }
    
    void findWordsTrie(vector<vector<char>>& board, vector<string> & words, Trie & trie, vector<string> & res) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        
        int M = board.size();
        int N = board[0].size();
        
        vector<vector<bool>> p(M, vector<bool>(N, false));
        
        solve(board, p, M, N, words, trie, res);
        
    }
    
    
    void solve(vector<vector<char>>& board, vector<vector<bool>> & p, int M, int N, vector<string> & words, Trie & trie, vector<string> & res) {
        
        string cur;
        for(int i=0; i < M; i++) {
            for(int j=0; j < N; j++) {
                if(!p[i][j]) {
                    p[i][j] = true;
                    cur.push_back(board[i][j]);
                    solveNext(board, p, M, N, words, trie, res, cur, i, j);
                    cur.pop_back();
                    p[i][j] = false;
                }
            }
        }
        
    }
    
    bool isValid(vector<vector<char>>& board, vector<vector<bool>> & p, int M, int N, int i, int j) {
        bool flag = false;
        if(i >= 0 && i < M && j >= 0 && j < N && !p[i][j])
            flag = true;
        return flag;
    }
    
    void solveNext(vector<vector<char>>& board, vector<vector<bool>> & p, int M, int N, vector<string> & words, Trie & trie, vector<string> & res, string & cur, int i, int j) {

//        cout << "cur:" << cur << endl;
        
        if(trie.startsWith(cur) == false) {
            return;
        }
        
        if(trie.search(cur)) {
            res.push_back(cur);
        }
        
        vector<vector<int>> vv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int k=0; k < vv.size(); k++) {
            int in = i + vv[k][0];
            int jn = j + vv[k][1];
            if(isValid(board, p, M, N, in, jn)) {
                p[in][jn] = true;
                cur.push_back(board[in][jn]);
                solveNext(board, p, M, N, words, trie, res, cur, in, jn);
                cur.pop_back();
                p[in][jn] = false;
            }
        }
    }
};

void printVecInt(vector<int> & v) {
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

int main() {

    Solution s;
    vector<vector<char>> vv;
    vector<string> words;
    vector<string> res;
    
    //test 1
    vv.push_back(vector<char>({'o','a','a','n'}));
    vv.push_back(vector<char>({'e','t','a','e'}));
    vv.push_back(vector<char>({'i','h','k','r'}));
    vv.push_back(vector<char>({'i','f','l','v'}));
    words = {"oath", "pea", "eat", "rain"};
    
    //test 2
//    vv.push_back(vector<char>({'a','a'}));
//    words = {"a"};
    
    res = s.findWords(vv, words);
    for(int i=0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}


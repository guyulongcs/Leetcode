#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

#include <algorithm>

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


int main() {
    Trie trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("abc");
    
    bool res;
    res = trie.search("apps");
    cout << res << endl;
    
    res = trie.search("app");
    cout << res << endl;
    
    res = trie.startsWith("ab");
    cout << res << endl;

    return 0;
}


nclude <iostream>
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
    
    bool searchReg(string word) {
        return searchRegNode(root, word);
    }
            
    bool searchRegNode(TrieNode* T, string word) {
//        cout << "searchRegNode" << endl;
//        cout << word << endl;
        bool flag = false;
        if(T == NULL)
            return false;
        if((word.length() == 0)) {
            if ((T != NULL) && (T->hasWord == true))
                return true;
            else
                return false;
        }
        
        
        if(word[0] == '.') {
            for(int i=0; i < (T->a).size(); i++) {
                TrieNode * node = (T->a)[i];
                if(node != NULL) {
                    if(searchRegNode(node, word.substr(1))) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        else {
            int index = word[0] - 'a';
            TrieNode * node = (T->a)[index];
            flag = searchRegNode(node, word.substr(1));
        }
        
        return flag;
    }
    
private:
    TrieNode* root;
};

class WordDictionary {
public:
    Trie trie;
    
    WordDictionary() {
        trie = Trie();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie.searchReg(word);
    }
};


int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("at");
    wordDictionary.addWord("and");
    wordDictionary.addWord("an");
    wordDictionary.addWord("add");
    cout << wordDictionary.search("a") << endl;
    cout << wordDictionary.search(".at") << endl;
    cout << wordDictionary.search("bat") << endl;
    cout << wordDictionary.search(".at") << endl;
    cout << wordDictionary.search("an.") << endl;
    cout << wordDictionary.search("a.d.") << endl;
    cout << wordDictionary.search("b.") << endl;
    cout << wordDictionary.search("a.d") << endl;
    cout << wordDictionary.search(".") << endl;
    
    return 0;
}


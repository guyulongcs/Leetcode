#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node {
    int key;
    int value;
    Node(){}
    Node(int k=0, int v=0):key(k), value(v){}
};

class LRUCache{
    unordered_map<int, list<Node>::iterator> cmap;
    list<Node> clist;
    //int ccnt;
    int capacity;
public:
    LRUCache(int capacity) {
        //ccnt=0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        int res = -1;
        if(cmap.find(key) != cmap.end()) {
            list<Node>::iterator it = cmap[key];
            int value = (*it).value;
            res = value;
            clist.erase(it);
            push_front(key, value);
            
        }
        return res;
    }
    
    void push_front(int key, int value) {
        Node newNode(key, value);
        clist.push_front(newNode);
        cmap[key] = clist.begin();
    }
    
    void removeLast() {
        Node curNode = clist.back();
        clist.pop_back();
        cmap.erase(curNode.key);
    }
    
    void set(int key, int value) {
        //has key
        if(cmap.find(key) != cmap.end()) {
            list<Node>::iterator it = cmap[key];
            clist.erase(it);
            push_front(key, value);
        }
        //not has key
        else {

            if(clist.size() == capacity) {
                removeLast();
            }
            push_front(key, value);            
        }
    }
    
};


int main() {
    LRUCache lru(2);
    lru.set(1,2);
    lru.set(3,4);
    lru.set(2,5);
    
    int flag = lru.get(1);
    cout << flag << endl;
   
    
    return 0;
}



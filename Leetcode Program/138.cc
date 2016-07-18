#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>


using namespace std;



struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode * head) {
        RandomListNode * node = NULL;
        RandomListNode * nHead = NULL;
        unordered_map<RandomListNode *, RandomListNode *> map;
        
        //map
        node = head;
        RandomListNode * pre = NULL;
        while(node != NULL) {
            RandomListNode * nnode = new RandomListNode(node->label);
            map[node] = nnode;
            if(nHead == NULL) {
                nHead = nnode;
                
            }
            else {
                pre->next = nnode;
            }
            pre = nnode;
            node = node->next;
        }
        
        
        //
        node = head;
        while(node != NULL) {
            RandomListNode * mnode = map[node];
            RandomListNode * rnode = node->random;
            if(rnode != NULL) {
                mnode->random = map[rnode];
            }
            node = node->next;
        }
        
        return nHead;
    }
};

int main() {


    Solution s;
    vector<int> v({1,2,3});
    return 0;
}


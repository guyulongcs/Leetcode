#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode * f = head;
        ListNode * s = head;
        bool flag = false;
        while(true) {
            s = nextNode(s);
            f = nextNode(nextNode(f));
            if( s== NULL && f == NULL)
                break;
            if( s==f) {
                flag = true;
                break;
            }
        }
        return flag;
    }
    
    ListNode * nextNode(ListNode * h) {
        if(h == NULL) {
            return NULL;
        }
        else {
            return h->next;
        }
    }
    
    
};

class CListNode {
public:
    ListNode * createList(vector<int> v) {
        ListNode * head = NULL;
        ListNode * p = NULL;
        for(int i=0;i<v.size();i++) {
            ListNode * node = new ListNode(v[i]);
            if(i==0) {
                head =node;
            }
            else {
                p->next = node;
            }
            p = node;
        }
        return head;
    }
    
    void printList(ListNode * T) {
        cout << "list:" << endl;
        ListNode * p = T;
        while(p != NULL){
            cout << p->val << "\t";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    

    Solution s;
    
    vector<int> v({1,2});
    CListNode list;
    ListNode * l = list.createList(v);
    bool res= s.hasCycle(l);
    cout << res << endl;
        
    return 0;
}


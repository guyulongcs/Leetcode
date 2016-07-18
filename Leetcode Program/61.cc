#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
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
    
    static int getListLen(ListNode * head) {
        int i=0;
        while(head != NULL) {
            i++;
            head=head->next;
        }
        return i;
    }
    static void printList(ListNode * T) {
        cout << "list:" << endl;
        ListNode * p = T;
        while(p != NULL){
            cout << p->val << "\t";
            p = p->next;
        }
        cout << endl;
    }
};


class Solution {
public:
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode * p1 = head;
        ListNode * p2 = head;
        
        int len = CListNode::getListLen(head);
        k = k % len;
        while(k--) {
            p2 = nextNode(p2);
        }
        
        if(p2 == NULL)
            return head;
        
        while(p2->next != NULL) {
            p1=nextNode(p1);
            p2 = nextNode(p2);
        }
        
    
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        
        return head;
    }
    
    
    ListNode * nextNode(ListNode * node) {
        if(node == NULL)
            return NULL;
        return node->next;
    }
};


int main() {
    

    Solution s;
    
    vector<int> v1({1,2,3});
    vector<int> v2({1,5,7,9});
    vector<int> v3({10,20});
    
    CListNode list;
    vector<ListNode *> vl;
    ListNode * l1 = list.createList(v1);
    ListNode * lm = s.rotateRight(l1, 4);
    list.printList(lm);
    
    return 0;
}


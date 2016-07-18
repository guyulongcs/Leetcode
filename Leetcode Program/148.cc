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

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
  
//        cout << endl << "before split" << endl;
//        CListNode::printList(head);
        
        ListNode * p2b = splitList(head);
        
//        cout  << "after split" << endl;
//        CListNode::printList(head);
//        CListNode::printList(p2b);
//        
        
    
        
        head = sortList(head);
        p2b = sortList(p2b);
        
//        cout << endl << "before merge" << endl;
//        CListNode::printList(head);
//        CListNode::printList(p2b);
        
        head = mergeList(head, p2b);
        
//        cout  << "after merge" << endl;
//        CListNode::printList(head);
        
        return head;
        
    }
    ListNode * mergeList(ListNode * l1, ListNode * l2) {
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * p = NULL;
        ListNode * prev = NULL;
        ListNode * h = NULL;
        while(true) {
            bool flag = false;
            if(l1 != NULL) {
                if(l2 == NULL ||  (l1->val < l2->val)) {
                    p=l1;
                    l1 = nextNode(l1);
                    flag =true;
                }
            }
            if(!flag) {
                p=l2;
                l2 = nextNode(l2);
            }
            
            if(h == NULL)
                h = p;
            if(prev != NULL)
                prev->next=p;
            prev = p;
            
            if(l1 == NULL && l2==NULL) {
                break;
            }
        }
        return h;
    }
    
    ListNode * splitList(ListNode* head) {
        ListNode * s = head;
        ListNode * prev = NULL;
        ListNode * f=head;
        while(true) {
            prev = s;
            s = nextNode(s);
            f = nextNode(nextNode(f));
            if(f == NULL) {
                break;
            }
        }
        prev->next = NULL;
        return s;
    }
    
    
    ListNode * nextNode(ListNode * node) {
        if(node == NULL)
            return NULL;
        return node->next;
    }
};


int main() {
    

    Solution s;
    
    vector<int> v({2,4,1});
    CListNode list;
    ListNode * l = list.createList(v);
    ListNode * l2 = s.sortList(l);
    list.printList(l2);
    
    return 0;
}


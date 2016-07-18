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
    
    static ListNode * reverseList(ListNode * head) {
        if(head == NULL)
            return NULL;
        ListNode * p = head;
        ListNode * prev = NULL;
        ListNode * pn;
        ListNode * pnn;
        while(p != NULL) {
            if(prev == NULL) {
                prev = p;
                p = CListNode::nextNode(p);
                prev->next = NULL;
                continue;
            }
            pn = CListNode::nextNode(p);
            p->next = prev;
            
            prev = p;
            p = pn;
           
        }
        return prev;
    }
    
    static ListNode * nextNode(ListNode * node) {
        if(node == NULL)
            return NULL;
        return node->next;
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
    
    void reorderList(ListNode * head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode * pf=head;
        ListNode * pe = getListHalfHead(head);
//        cout << endl << "pe" << endl;
//        CListNode::printList(pe);

        
        pe = CListNode::reverseList(pe);
//        
////        cout << endl << "pf" << endl;
////        CListNode::printList(pf);
//////
////        cout << endl << "pe" << endl;
//        CListNode::printList(pe);

        
        ListNode * pf2;
        ListNode * pe2;
        head = pf;
        while(true) {
            pf2=nextNode(pf);
            pe2=nextNode(pe);
            pf->next = pe;
            pe->next = pf2;
            pf = pf2;
            pe = pe2;
            if(pf == NULL || pe == NULL)
                break;
        }
        
    }
    
    ListNode * getListHalfHead(ListNode * head) {
        if(head == NULL)
            return NULL;
        ListNode * s = head;
        ListNode * f = head;
        ListNode * sprev = NULL;
        while(f!=NULL) {
            sprev = s;
            s=nextNode(s);
            
            f=nextNode(nextNode(f));
        }
        if(sprev != NULL)
            sprev->next = NULL;
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
    
    vector<int> v1({1,2,3});
    vector<int> v2({1,5,7,9});
    vector<int> v3({10,20});
    
    CListNode list;
    vector<ListNode *> vl;
    ListNode * l1 = list.createList(v1);
    s.reorderList(l1);
    list.printList(l1);
    
    return 0;
}


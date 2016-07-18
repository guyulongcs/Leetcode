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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        int la = getListLen(headA);
        int lb = getListLen(headB);
        ListNode * inode = NULL;
        int ldiff = abs(la-lb);
        if(la >= lb) {
            inode = getIntersectionNodeOrder(headA, headB, ldiff);
        }
        else {
            inode = getIntersectionNodeOrder(headB, headA, ldiff);
        }
        return inode;
    }
    
    ListNode * getIntersectionNodeOrder(ListNode *headA, ListNode *headB, int ldiff) {
        ListNode * p1 = headA;
        ListNode * p2 = headB;
        while(ldiff > 0) {
            p1 = p1->next;
            ldiff--;
        }
        ListNode * inode = NULL;
        while(true) {
            if(p1 == p2) {
                inode = p1;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == NULL || p2 == NULL) {
                break;
            }
        }
        return inode;
        
    }
    
    int getListLen(ListNode * head) {
        int i=0;
        while(head != NULL) {
            i++;
            head = head->next;
        }
        return i;
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
    ListNode * res = s.getIntersectionNode(l, l);
    if(res != NULL)
        cout << res->val << endl;
        
    return 0;
}


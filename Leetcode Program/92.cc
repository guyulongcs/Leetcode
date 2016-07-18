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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
            return NULL;
        
        if(m < 1)
            m=1;
        ListNode * p0 = NULL;
        ListNode * p1 = head;
        ListNode * p2 = head->next;
        ListNode * pb=NULL;
        ListNode * pe = NULL;
        for(int i=1; i <= n;i++) {
            if(i < m) {
                p0 = p1;
                p1=p2;
                p2 = p1->next;
            }
            if(i == m) {
                pe = p1;
            }
            if(i >= m && i < n) {
                if(p2 == NULL) {
                    break;
                }
                ListNode * p = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p;
            }
            if(i == n) {
                break;
            }
        }
        pb = p1;
        if(p0 == NULL)
            p0=pb;
        else
            p0->next = pb;
        pe->next = p2;
        if(m==1)
            head = pb;
        return head;
    }
    
    ListNode * reverseList(ListNode * head) {
        if(head == NULL)
            return NULL;
        
        ListNode * p1 = head;
        ListNode * p2 = p1->next;
        ListNode * p3 = NULL;
        while(true) {
            if(p2 == NULL)
                break;
            p3 = p2->next;
            p2->next = p1;
            if(p1 == head) {
                p1->next = NULL;
            }
            p1 = p2;
            p2 = p3;
            if(p2 == NULL)
                break;
        }
        return p1;
        
    }
    
    ListNode * nextNode(ListNode * node) {
        if(node == NULL)
            return NULL;
        return node->next;
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
    
    vector<int> v({1,2,3});
    CListNode list;
    ListNode * l = list.createList(v);
    ListNode * l2 = s.reverseBetween(l, 1,2);
    list.printList(l2);
    
    return 0;
}


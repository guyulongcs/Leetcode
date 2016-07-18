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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL)
            return NULL;
        
        ListNode * pl1 = NULL;
        ListNode * pl2 = NULL;
        ListNode * pg1 = NULL;
        ListNode * pg2 = NULL;
        
        ListNode * p= head;
        while(p != NULL) {
//            cout << endl << "p:" << p->val << endl;
            if(p->val < x) {
//                cout << "<" << endl;
                if(pl1 == NULL)
                    pl1 = p;
                if(pl2 == NULL)
                    pl2 = p;
                else {
                    pl2->next = p;
                    pl2 = p;
                }
            }
            else {
//                cout << ">=" << endl;
                if(pg1 == NULL)
                    pg1 = p;
                if(pg2 == NULL)
                    pg2 = p;
                else {
                    pg2->next = p;
                    pg2 = p;
                }
            }
//            
//            cout  << "pl...." << endl;
//            
//            if(pl1)
//                cout << "pl1:" << pl1->val << endl;
//            if(pl2)
//                cout << "pl2:" << pl2->val << endl;
//            if(pg1)
//                cout << "pg1:" << pg1->val << endl;
//            if(pg2)
//                cout << "pg2:" << pg2->val << endl;
//            
            p = p->next;
        }
        
        
        if(pl2 != NULL)
            pl2->next = pg1;
        if(pg2 != NULL)
            pg2->next = NULL;
        //pg2->next = NULL;
        if(pl1 == NULL)
            pl1 = pg1;
        
        return pl1;
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
    
    vector<int> v({8,1,4,3,2,6,5});
    CListNode list;
    ListNode * l = list.createList(v);
    ListNode * res = s.partition(l, 3);
    list.printList(res);
    
    return 0;
}


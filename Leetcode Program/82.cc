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



class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode * p1 = head;
        ListNode * prev = NULL;
        
        bool flagVal = false;
        int val_delete = 0;
        while(p1 != NULL) {
            bool flag = false;
            
            if(!flag) {
                flag = (flagVal) && (val_delete == p1->val);
            }
            
            if(!flag) {
                flag = (p1->next != NULL) && (p1->next->val == p1->val);
            }
            
            if(flag) {
                flagVal = true;
                val_delete = p1->val;
                ListNode * oldNode = p1;
                p1 = p1->next;
                if(prev != NULL)
                    prev ->next = p1;
                else
                    head = p1;
                delete oldNode;
                
            }
            else {
                flagVal = false;
                prev = p1;
                p1 = p1->next;
            }
        }
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
    
    vector<int> v({0,1,2,2,3});
    CListNode list;
    ListNode * l = list.createList(v);
    ListNode * l2 = s.deleteDuplicates(l);
    list.printList(l2);
    
    return 0;
}


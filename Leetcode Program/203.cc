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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode * p = head;
        ListNode * prev = NULL;
        while(p != NULL) {
            if(p->val == val) {
                if(p == head) {
                    
                    head = p->next;
                    prev = NULL;
                    
                }
                else {
                    prev->next = p->next;
                }
            }
            else {
                prev = p;
            }
            p = p->next;
        }
        return head;
        
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
    
    vector<int> v({8,8,1,4,8,3,2,6,5});
    CListNode list;
    ListNode * l = list.createList(v);
    ListNode * res = s.removeElements(l, 8);
    list.printList(res);
    
    return 0;
}


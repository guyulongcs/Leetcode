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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p1 = head;
        ListNode * cur = head;
        ListNode * p2 =head;
        
        ListNode * oldNode = NULL;
        
        if(head == NULL)
            return NULL;
        
        n++;
        while(n) {
            
            cur = p2;
            if(p2 == NULL)
                break;
            p2 = p2->next;
            
            n--;
        }
        while(p2 != NULL) {
            if(p1 == NULL)
                break;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if(cur == NULL ) {
            oldNode= head;
            head = head->next;
            delete oldNode;
            
        }
        else {
            oldNode = p1->next;
            if(p1->next != NULL) {
                p1->next = p1->next->next;
                delete oldNode;
            }
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
    
    vector<int> v({1,2,3,4,5});
    CListNode list;
    ListNode * l = list.createList(v);
    ListNode * res = s.removeNthFromEnd(l, 6);
    list.printList(res);
    
    return 0;
}


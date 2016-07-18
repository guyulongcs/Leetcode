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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * p1 = head;
        ListNode * p2 = head->next;
        ListNode * prev = head;
        ListNode * headN = head;
        
        while(true) {
            prev->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            if(p1 == head) {
                headN = p2;
            }
            prev = p1;
            p1= p1->next;
            
            if(p1 != NULL)
                p2 = p1->next;
            else
                p2 = NULL;
            if(p1 == NULL || p2 == NULL) {
                break;
            }
        }
        return headN;
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
    ListNode * l2 = s.swapPairs(l);
    list.printList(l2);
        
    return 0;
}


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
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head ->next == NULL)
            return true;
        
        ListNode * p1=head;
        ListNode * p2 = head;
        while(true) {
            p1 = nextNode(p1);
            p2 = nextNode(nextNode(p2));
            if(p2 == NULL || p2->next == NULL || p2->next->next == NULL)
                break;
        }
        
        p2 = reverseList(p1);
        ListNode * p3 = head;
        
        bool flag = true;
        while(true) {
            if(p3->val != p2->val) {
                flag = false;
                break;
            }
            p3=p3->next;
            p2 = p2->next;
            if(p3 == NULL || p2 == NULL)
                break;
        }
        
        p1 = reverseList(p1);
        
        return flag;
        
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
    
    vector<int> v({1});
    CListNode list;
    ListNode * l = list.createList(v);
    bool  res = s.isPalindrome(l);
    cout << res << endl;
    
    return 0;
}


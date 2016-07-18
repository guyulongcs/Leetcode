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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode * curNode = head;
        ListNode * minNode = head;
        ListNode * prevNode = NULL;
        ListNode * minPrevNode = NULL;
        while(true) {

            minPrevNode = findMinNode(curNode);
            
            if(minPrevNode == NULL) {
                prevNode = curNode;
                curNode = curNode->next;
            }
            else {
                minNode = minPrevNode->next;

                if(prevNode != NULL) {
                    prevNode->next = minNode;
                }
                minPrevNode->next = minNode->next;
                minNode->next = curNode;
                if(curNode == head) {
                    prevNode = minNode;
                    head = minNode;
                }
                else {
                    prevNode = prevNode->next;
                    curNode = minNode->next;
                }
            }
            
            if(curNode == NULL)
                break;
        }
        return head;
    }
    
    ListNode* findMinNode(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode * p = head;
        ListNode * minNode = head;
        ListNode * prevNode = NULL;
        ListNode * minPrevNode = NULL;
        int minVal = INT32_MAX;
        
        while(true) {
            //prevNode = p;
            //p = p->next;
            
            if(p == NULL)
                break;
            if(p->val < minVal) {
                
                minVal = p->val;
                minNode = p;
                minPrevNode = prevNode;
            }
            prevNode = p;
            p=p->next;
        }
        return minPrevNode;
    }
    
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
    vector<int> v({3,2,4,1});
    ListNode * ln = s.createList(v);
    ListNode * lns = s.insertionSortList(ln);
    
    s.printList(lns);
    
    int res = 0;
   // cout << res << endl;
    
    return 0;
}


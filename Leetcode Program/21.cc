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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * l = NULL;
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * p = NULL;
        
        while(p1 != NULL || p2 != NULL) {
            ListNode * pc = NULL;
            
            bool flag = false;
            if(p1 != NULL) {
                if(p2 == NULL || (p1->val < p2->val)){
                    flag = true;
                    pc = p1;
                    p1=p1->next;
                }
            }
            if(!flag){
                pc = p2;
                p2 = p2->next;
            }
            if(p == NULL) {
                l = pc;
                p = pc;
            }
            else {
                p->next = pc;
                p = pc;
            }
        }
        return l;
    }
    
    
};

int main() {
    

    Solution s;
    
    
    return 0;
}


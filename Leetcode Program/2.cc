#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * p3 = NULL;
        ListNode * l3=p3;
        int c=0;
        while(true) {
            int n1=0;
            int n2=0;
            if(p1 != NULL) {
                n1 = p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL) {
                n2 = p2->val;
                p2 = p2->next;
            }
            int n = n1 + n2 + c;
            
            int num = n%10;
            
            ListNode * node = new ListNode(num);
            if(p3 == NULL) {
                l3 = node;
                p3 = node;
            }
            else {
                p3->next = node;
                p3 = p3->next;
            }
            c = n/10;
            if(p1 == NULL && p2 == NULL && c==0) {
                break;
            }
        }
        return l3;
    }
    
};


int main() {
    

    Solution s;
    
    


    return 0;
}


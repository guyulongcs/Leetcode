/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
            
        ListNode * p1 = head;
        ListNode * p2 = head -> next;
        
        head -> next = NULL;
        while(true) {
            if(p2 == NULL)
                break;
            ListNode * tmp = p2->next;
            p2 -> next = p1;
            
            p1 = p2;
            p2 = tmp;
            
        }
        return p1;
    }
};

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode * p=head;
        ListNode * p1, * p2, *pe;
        p1=head;
        pe = p1->next;
        while((p1!= NULL) && (p1->next != NULL)) {
            p2 = p1->next;
            p1->next = p2->next;
            if(p2->next != NULL) {
                p2->next = p2->next->next;
            }
            if(p1->next != NULL){
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        p1->next = pe;
        return p;
    }
};

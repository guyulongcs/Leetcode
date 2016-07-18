#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
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
    static void printList(ListNode * T) {
        cout << "list:" << endl;
        ListNode * p = T;
        while(p != NULL){
            cout << p->val << "\t";
            p = p->next;
        }
        cout << endl;
    }
};

class PQItem {
public:
    ListNode * l;
    int len;
    
public:
    PQItem():l(NULL), len(0){}
    PQItem(ListNode * p, int len):l(p), len(len) {}
    
//    bool operator < (const PQItem & pq2) {
//        return this->len < pq2.len;
//    }
//
//    bool operator > (const PQItem & pq2) {
//        return this->len > pq2.len;
//    }
//    
    
    friend bool operator < (const PQItem & pq1, const PQItem & pq2) {
        return pq1.len < pq2.len;
    }
    
    friend bool operator > (const PQItem & pq1, const PQItem & pq2) {
        return pq1.len > pq2.len;
    }

};

class Cmp {
public:
    bool operator() (const PQItem & lhs, const PQItem &rhs) const
    {
        return lhs.len > rhs.len;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = NULL;
        
        priority_queue<PQItem, vector<PQItem>, greater<PQItem>> pq;
        //priority_queue<PQItem, vector<PQItem>, Cmp> pq;
        
        for(int i=0; i < lists.size(); i++ ) {
            ListNode * l = lists[i];
            int len = CListNode::getListLen(l);
            PQItem pqItem(l, len);
            pq.push(pqItem);
        }
        
//        cout << "top:" << pq.top().len << endl;
        
        while(true) {
            if(pq.size() == 0)
                break;
            if(pq.size() == 1) {
                head = pq.top().l;
                break;
            }
            PQItem item1 = pq.top();
            pq.pop();
            PQItem item2 = pq.top();
            pq.pop();
            
            ListNode * lm = mergeList(item1.l, item2.l);
            int len = item1.len + item2.len;
            PQItem pqItem(lm, len);
            pq.push(pqItem);
        }
        return head;
    }

    ListNode* mergeKLists0(vector<ListNode*>& lists) {
        ListNode * head = NULL;
        for(int i=0; i < lists.size(); i++ ) {
            ListNode * l = lists[i];
            head = mergeList(head, l);
        }
        return head;
    }
    
    ListNode * mergeList(ListNode * l1, ListNode * l2) {
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * p = NULL;
        ListNode * prev = NULL;
        ListNode * h = NULL;
        while(true) {
            bool flag = false;
            if(l1 != NULL) {
                if(l2 == NULL ||  (l1->val < l2->val)) {
                    p=l1;
                    l1 = nextNode(l1);
                    flag =true;
                }
            }
            if(!flag) {
                p=l2;
                l2 = nextNode(l2);
            }
            
            if(h == NULL)
                h = p;
            if(prev != NULL)
                prev->next=p;
            prev = p;
            
            if(l1 == NULL && l2==NULL) {
                break;
            }
        }
        return h;
    }
    
    ListNode * splitList(ListNode* head) {
        ListNode * s = head;
        ListNode * prev = NULL;
        ListNode * f=head;
        while(true) {
            prev = s;
            s = nextNode(s);
            f = nextNode(nextNode(f));
            if(f == NULL) {
                break;
            }
        }
        prev->next = NULL;
        return s;
    }
    
    
    ListNode * nextNode(ListNode * node) {
        if(node == NULL)
            return NULL;
        return node->next;
    }
};


int main() {
    

    Solution s;
    
    vector<int> v1({2,4,8});
    vector<int> v2({1,5,7,9});
    vector<int> v3({10,20});
    
    CListNode list;
    vector<ListNode *> vl;
    ListNode * l1 = list.createList(v1);
    ListNode * l2 = list.createList(v2);
    ListNode * l3 = list.createList(v3);
    vl.push_back(l1);
    vl.push_back(l2);
    vl.push_back(l3);
    
    ListNode * lm = s.mergeKLists(vl);
    list.printList(lm);
    
    return 0;
}


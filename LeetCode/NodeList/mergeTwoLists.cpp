#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(-105, list1);
    auto p = &dummy; 
    auto q = list2;

    while (q) {
        while (1) {
            if (!p->next || (p->val <= q->val && q->val <= p->next->val)) {
                p->next = new ListNode(q->val, p->next);
                p = p->next;
                break;
            }
            p = p->next;    
        }
        q = q->next;
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

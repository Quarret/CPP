#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    ListNode dummy(-1, head);
    auto cur = &dummy;

    while (cur->next && cur->next->next) {
        auto nxt = cur->next;
        int val = -1;
        if (nxt->val == nxt->next->val) {
            val = nxt->val;
    
            while (cur->next->val == val) {
                cur->next = cur->next->next;
            }
        } else {
            cur = cur->next;
        }
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

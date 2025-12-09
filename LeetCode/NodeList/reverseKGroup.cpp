#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
    int n = 0;
    auto p = head;
    while (p) {
        n++;
        p = p->next;
    }

    ListNode dummy(0, head);
    auto p0 = &dummy;
   
    while (n >= k) {
        n -= k;

        ListNode* pre = nullptr;
        auto cur = p0->next; 
        for (int i = 0; i < k; i++) {
            auto nxt = cur->next;
            cur->next = pre;

            pre = cur;
            cur = nxt;
        }

        auto nxt = p0->next;
        nxt->next = cur;
        p0->next = pre;
        p0 = nxt;
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

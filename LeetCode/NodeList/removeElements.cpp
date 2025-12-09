#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0, head);
    auto cur = &dummy;
    while (cur->next) {
        auto nxt = cur->next;
        if (nxt->val == val) {
            cur->next = nxt->next;
        } else {
            cur = nxt;
        }
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

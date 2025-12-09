#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* partition(ListNode* head, int x) {
    if (!head) return nullptr;

    ListNode dummy(0, head);
    ListNode *before = &dummy, *cur = &dummy;
    while (cur->next && cur->next->val < x) {
        before = before->next;
        cur = cur->next;
    }
    

    while (cur && cur->next) {
        while (cur->next && cur->next->val < x) {
            auto nxt = before->next;
            before->next = cur->next;

            cur->next = cur->next->next;
            before->next->next = nxt;
            before = before->next;
        }
        cur = cur->next;
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

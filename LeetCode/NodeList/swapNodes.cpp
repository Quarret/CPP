#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* swapNodes(ListNode* head, int k) {
    ListNode dummy(0, head);
    auto right = &dummy;

    for (int i = 0; i < k; i++) {
        right = right->next;
    }
    auto prev = right;

    auto left = &dummy;
    while (right->next) {
        right = right->next;
        left = left->next;
    }

    int val1 = prev->val, val2 = left->next->val;
    prev->val = val2;
    left->next->val = val1;

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

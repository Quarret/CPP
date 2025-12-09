#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    auto right = &dummy;

    for (int i = 0; i < n; i++) {
        right = right->next;
    }

    auto left = &dummy;
    while (right->next) {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

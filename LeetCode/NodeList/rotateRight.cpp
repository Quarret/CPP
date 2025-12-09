#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;

    auto cur = head;
    int n = 0;
    while (cur) {
        n++;
        cur = cur->next;
    }

    k = k % n;
    if (k == 0) return head;

    ListNode dummy(0, head);
    auto right = &dummy;
    for (int i = 0; i < k; i++) {
        right = right->next;
    }

    auto left = &dummy;
    while (right->next) {
        right = right->next;
        left = left->next;
    }

    auto ans = left->next;
    left->next = nullptr;
    right->next = head;

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

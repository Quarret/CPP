#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;

    auto odd = head, even = head->next, head2 = even;
    while (odd && odd->next && even && even->next) {
        odd->next = even->next;
        auto nxt = even->next;
        even->next = nxt->next;

        odd = nxt;
        even = nxt->next;
    }
    odd->next = head2;

    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

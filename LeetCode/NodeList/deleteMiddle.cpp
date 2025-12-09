#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) return nullptr;

    ListNode dummy(0, head);
    auto slow = &dummy;
    auto fast = &dummy;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

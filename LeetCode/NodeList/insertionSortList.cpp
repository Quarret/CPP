#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(-10000, nullptr);

    auto cur = head;
    while (cur) {
        int val = cur->val;

        auto cur1 = &dummy;
        while (cur1) {
            if (cur1->next == nullptr) {
                cur1->next = new ListNode(val, nullptr);
                break;
            }

            int val1 = cur1->val, val2 = cur1->next->val;
            if (val >= val1 && val <= val2) {
                cur1->next = new ListNode(val, cur1->next);
                break;
            }

            cur1 = cur1->next;
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

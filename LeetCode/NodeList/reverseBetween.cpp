#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0, head);
    auto cur = &dummy;
    
    for (int i = 0; i < left - 1; i++) {
        cur = cur->next;
    }
    auto p0 = cur;
    cur = cur->next;

    ListNode* pre;
    for (int i = 0; i < right - left + 1; i++) {
        auto nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    p0->next->next = cur;
    p0->next = pre;

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* reverseEvenLengthGroups(ListNode* head) {
    int n = 0;
    auto cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }

    ListNode dummy(0, head);
    auto p0 = &dummy;
    int flag = n;
    for (int i = 1; i <= n; i++) {
        int len = min(i, flag);
        flag -= len;
        if (flag < 0) break;

        if (len % 2) {
            for (int j = 0; j < len; j++) {
                p0 = p0->next;
            }
        } else {
            ListNode* pre = nullptr;
            auto cur = p0->next;
            for (int j = 0; j < len; j++) {
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
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

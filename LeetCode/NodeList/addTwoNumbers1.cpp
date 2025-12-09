#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto reverseList = [&](ListNode* head) -> ListNode* {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            auto nxt = cur->next;
            cur->next = pre;

            pre = cur;
            cur = nxt;
        }

        return pre;
    };

    auto head1 = reverseList(l1);
    auto head2 = reverseList(l2);

    ListNode dummy(0, nullptr);
    auto add = [&](ListNode* l1, ListNode* l2) -> ListNode* {
        auto cur = &dummy;
        auto p = l1, q = l2;
        int flag = 0;
        while (p || q) {
            int val1 = 0, val2 = 0;
            if (p) {
                val1 = p->val;
                p = p->next;
            }
            if (q) {
                val2 = q->val;
                q = q->next;
            }
            int val = (val1 + val2 + flag) % 10;
            flag = (val1 + val2 + flag) / 10;
            cur->next = new ListNode(val, cur->next);
            cur = cur->next;
        }
    
        if (flag) cur->next = new ListNode(1, cur->next);
    
        return dummy.next;
    };

    auto head3 = add(head1, head2);
    auto ans = reverseList(dummy.next);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* doubleIt(ListNode* head) {
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

    auto head1 = reverseList(head);
    ListNode dummy(0, head1);
    
    auto cur = head1, tail = head1;
    int carry = 0;
    while (cur) {
        if (cur) carry += 2 * cur->val;
        cur->val = carry % 10;
        carry /= 10;
        if (!cur->next) tail = cur;
        cur = cur->next;
    }
    if (carry) tail->next = new ListNode(carry, tail->next);

    auto ans = reverseList(dummy.next);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* removeNodes(ListNode* head) {
    ListNode dummy(0, head);
    auto r = &dummy, l = &dummy;

    int minn = 1e9;
    while (r) {
        int val = r->val;
        auto cur = l;
        while (val > minn && &*cur != &*r) {
            if (cur->next->val < val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        minn = val;
        r = r->next;
    }

    return l->next;
}

ListNode* removeNodes(ListNode* head) {
    if (head->next == nullptr) {
        return head;
    }

    ListNode* node = removeNodes(head->next);
    if (node->val > head->val) {
        return node;
    }

    head->next = node;
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

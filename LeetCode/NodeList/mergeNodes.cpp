#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    auto tail = dummy;

    for (auto cur = head -> next; cur -> next; cur = cur -> next) {
        if (cur -> val) {
            tail -> val += cur -> val;
        } else {
            tail -> next = new ListNode(0);
            tail = tail -> next;
        }
    }

    tail -> next = nullptr;
    return dummy;
}

ListNode* mergeNodes(ListNode* head) {
    ListNode* tail;
    auto begin = tail;
    for (auto cur = head -> next; cur -> next; cur = cur -> next) {
        if (cur -> val) {
            tail -> val += cur -> val;
        } else {
            tail = tail -> next;
            tail -> val = 0;
        }
    }

    tail -> next = nullptr;
    return begin;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

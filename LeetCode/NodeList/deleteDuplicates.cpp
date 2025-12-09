#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    auto cur = head;
    if (head == nullptr) return head;

    while (cur->next) {
        auto nxt = cur->next;
        if (nxt->val == cur->val) {
            cur->next = nxt->next;
        } else {
            cur = cur->next;
        }
    }
    
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

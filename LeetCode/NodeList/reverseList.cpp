#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    auto cur = head;
    
    while (cur) {
        auto nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

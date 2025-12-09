#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto p = headA, q = headB;
    while (p != q) {
        p = p ? p->next : headB;
        q = q ? q->next : headA;
    }

    return p;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

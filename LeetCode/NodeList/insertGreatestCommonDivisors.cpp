#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    auto cur = head;
    while (cur->next) {
        int val1 = cur->val, val2 = cur->next->val;
        cur->next = new ListNode(gcd(val1, val2), cur->next); // new 是真实的给该node分配了内存
        /*
        ListNode node(gcd(val1, val2), cur->next) // 局部变量, 栈内存
        cur -> next = &node;
        */
        cur = cur->next->next;
    }

    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

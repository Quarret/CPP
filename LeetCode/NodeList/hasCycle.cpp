#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

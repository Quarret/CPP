#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    int idx = 0;
    auto cur1 = list2;
    for (auto cur = list1; cur; cur = cur->next, idx++) {
        if (idx == a - 1) {
            cur1 = cur;
            cur = cur->next;
            idx++;

            cur1->next = list2;
            while (cur1->next) {
                cur1 = cur1->next;
            }
        }

        if (idx == b + 1) {
            cur1->next = cur;
        }
    }

    return list1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

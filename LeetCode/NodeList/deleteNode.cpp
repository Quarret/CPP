#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

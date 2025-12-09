#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    ListNode dummy(0, head);
    auto cur = &dummy;

    unordered_map<int, int> mp;
    for (int x : nums) mp[x] = 1;

    while (cur->next) {
        auto nxt = cur->next;
        if (mp[nxt->val]) {
            cur->next = nxt->next;
        } else {
            cur = cur->next;
        }
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

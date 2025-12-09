#include <bits/stdc++.h>
#include "ListNode.h"
using i64 = long long;
using namespace std;

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    ListNode dummy(0, head);
    unordered_map<int, int> mp;
    for (int x : nums) {
        mp[x] = 1;
    }

    auto cur = &dummy;
    while (cur->next) {
        int val = cur->next->val;
        if (mp[val]) {
            cur->next = cur->next->next;
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

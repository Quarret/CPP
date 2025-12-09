#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy(0, head);

    while (1) {
        auto cur = &dummy;
        int pre = 0;
        unordered_map<int, ListNode*> mp;
        while (cur) {
            pre += cur->val;
            if (mp[pre]) {
                auto nxt = cur->next;
                mp[pre]->next = nxt;
                break;
            } else {
                mp[pre] = cur;
            }
            cur = cur->next; 
        }

        if (mp[pre] && cur) continue;
        return dummy.next;
    }
    
    return dummy.next;
}

// 相同hash值, 后覆盖前, 保证后续删除不影响删除区间右端点后的前缀和
ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy(0, head);
    auto cur = &dummy;
    unordered_map<int, ListNode*> mp;
    int pre = 0;

    while (cur) {
        pre += cur->val;
        mp[pre] = cur;
        cur = cur->next;
    }

    cur = &dummy;
    pre = 0;
    while (cur) {
        pre += cur->val;
        cur->next = mp[pre]->next;
        cur = cur->next;
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

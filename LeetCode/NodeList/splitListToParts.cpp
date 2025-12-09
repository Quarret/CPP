#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    auto dummy = head;
    while (dummy) {
        len++;
        dummy = dummy -> next;
    }
    
    int q = len / k, r = len % k;
    vector<ListNode*> ans(k, nullptr);
    auto cur = head;
    for (int i = 0; i < k; i ++) {
        auto tail = cur ? new ListNode(0) : nullptr;
        ans[i] = tail;
        int l = r ? q + 1 : q;

        while (cur) {
            tail -> val = cur -> val;
            tail -> next = cur -> next;
            cur = cur -> next;
            l--;
            
            if (l) {
                tail = tail -> next;
            } else {
                tail -> next -> next = nullptr;
                break;
            }
        }
        r--;
    }

    return ans;
}


vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    for (auto dummy = head; dummy; dummy = dummy -> next) {
        len++;
    }

    int l = len / k;
    int r = len % k;

    vector<ListNode*> ans(k, nullptr);
    auto tail = head;
    auto prev = head;

    for (int i = 0; i < k; i++, r--) {
        ans[i] = tail;
        for (int j = 0; j < l + (r > 0); j++) {
            prev = tail;
            tail = tail -> next;
        }
        if (prev) prev -> next = nullptr;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 1; i++) {
        cout << 1 << '\n';
    }

    return 0;
}

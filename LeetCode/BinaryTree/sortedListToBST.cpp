#include <bits/stdc++.h>
#include "TreeNode.h"
#include "ListNode.h"
using i64 = long long;
using namespace std;

// 直接操作链表
TreeNode* sortedListToBST(ListNode* head) {
    auto middle = [&](ListNode* head) -> ListNode* {
        auto fast = head, slow = head;
        ListNode* pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr;
        return slow;
    };
    
    auto dfs = [&](this auto&& dfs, ListNode* head) -> TreeNode* {
        // l + 1 >= r
        if (!head) {
            return nullptr;
        }

        // (l + 1, r) 区间只有一个元素
        if (!head->next) {
            return new TreeNode(head->val);
        }

        auto head2 = middle(head);
        return new TreeNode(head2->val, dfs(head), dfs(head2->next));
    };

    return dfs(head);
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    auto cur = head;
    while (cur) {
        nums.push_back(cur->val);
        cur = cur->next;
    }
    int n = nums.size();

    auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
        if (l + 1 >= r) {
            return nullptr;
        }

        int mid = l + (r - l) / 2;
        return new TreeNode(nums[mid], dfs(l, mid), dfs(mid, r));
    };

    return dfs(-1, n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

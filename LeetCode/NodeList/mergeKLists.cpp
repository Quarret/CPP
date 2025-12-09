#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto head : lists) {
        auto cur = head;
        while (cur) {
            pq.push(cur->val);
            cur = cur->next;
        }
    }

    ListNode dummy(0, nullptr);
    auto cur = &dummy;
    while (!pq.empty()) {
        int val = pq.top();
        pq.pop();

        cur = cur->next = new ListNode(val, cur->next);
    }

    return dummy.next;
}

// 分治 + 递归
class Solution {
    // 21. 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy{}; // 用哨兵节点简化代码逻辑
        auto cur = &dummy; // cur 指向新链表的末尾
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            } else { // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy.next;
    }

    // 合并从 lists[i] 到 lists[j-1] 的链表
    ListNode* mergeKLists(vector<ListNode*>& lists, int i, int j) {
        int m = j - i;
        if (m == 0) {
            return nullptr; // 注意输入的 lists 可能是空的
        }
        if (m == 1) {
            return lists[i]; // 无需合并，直接返回
        }
        auto left = mergeKLists(lists, i, i + m / 2); // 合并左半部分
        auto right = mergeKLists(lists, i + m / 2, j); // 合并右半部分
        return mergeTwoLists(left, right); // 最后把左半和右半合并
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size());
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto mergeTwoLists = [&](ListNode* l1, ListNode* l2) -> ListNode* {
        ListNode dummy{};
        auto cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = l1 ? l1 : l2;
        return dummy.next;
    };
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* sortList(ListNode* head) {
    priority_queue<int, vector<int>, greater<>> pq;
    auto cur = head;
    while (cur) {
        pq.push(cur->val);
        cur = cur->next;
    }

    ListNode dummy(0, nullptr);
    cur = &dummy;
    while (!pq.empty()) {
        int val = pq.top();
        pq.pop();
        cur = cur->next = new ListNode(val, cur->next);
    }

    return dummy.next;
}


// 分治 + 快慢指针 + 合并链表

// 快慢指针找中间节点
ListNode* middleNode(ListNode* head) {
    auto pre = head;
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // 断开left 与 right 的连接
    pre->next = nullptr;
    return slow;
}

// 21. 合并两个有序链表（双指针）
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy; // 用哨兵节点简化代码逻辑
    ListNode* cur = &dummy; // cur 指向新链表的末尾
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

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    // [1,2,3,4] -> [1, 2] [3, 4]
    auto head2 = middleNode(head);
    // 分治
    head = sortList(head);
    head2 = sortList(head2);
    // 合并
    return mergeTwoLists(head, head2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

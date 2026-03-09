#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (ListNode* cur = head; cur; cur = cur->next) {
        pq.push(cur->val);
    }
    
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (!pq.empty()) {
        cur = cur->next = new ListNode(pq.top());
        pq.pop();
    }

    return dummy.next;
}


// 找到链表中间节点 -- 快慢指针
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* pre = head;
    while (fast && fast->next) { // 
        pre = slow; // 记录 slow 前一个节点
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;

    // 中间节点: 奇数个节点最中间的, 偶数中间后者
    return slow;
}


// 合并有序链表
ListNode* mergeSortedList(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    
    cur->next = list1 ? list1 : list2;
    return dummy.next;
}

// 归并排序
ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* head2 = middleNode(head);
    head = sortList(head);
    head2 = sortList(head2);

    return mergeSortedList(head, head2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    auto dummy = head->next;
    ListNode* pre = head;   
    auto cur = head->next;
    while (1) {
        auto nxt = cur->next;
        cur->next = pre;
        if (!nxt || !nxt->next) {
            pre->next = nxt;
            break;
        }
        pre->next = nxt->next;

        pre = nxt;
        cur = nxt->next;
    }

    return dummy;
}

ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0, head);
    auto node0 = &dummy;
    auto node1 = head;
    
    while (node1 && node1->next) { //不足二不交换
        auto node2 = node1->next;
        auto node3 = node2->next;

        // 交换
        node0->next = node2;
        node2->next = node1;
        node1->next = node3;

        node0 = node1; // 下一轮交换 0 是 1
        node1 = node3; // 下一轮交换 1 是 3
    }

    return dummy.next;
}

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) { // 不足2
        return head;
    }

    auto node1 = head;
    auto node2 = node1->next;
    auto node3 = node2->next;
    node1->next = swapPairs(node3); // 1 指向递归返回的链表头
    node2->next = node1; // 2 指向 1

    return node2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

void reorderList(ListNode* head) {
    auto middleNode = [&](ListNode* head) -> ListNode* {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    };

    auto reverseList = [&](ListNode* head) -> ListNode* {
        ListNode *pre = nullptr, *cur = head;// cpp 中指针正确的写法 int *a, 而不是 int* a
        while (cur) {
            auto nxt = cur->next;
            cur->next = pre;

            pre = cur;
            cur = nxt;
        }

        return pre;
    };

    auto mid = middleNode(head);
    auto head2 = reverseList(mid);
    auto cur = head;

    while (head2->next) {
        auto nxt1 = cur->next;
        auto nxt2 = head2->next;

        cur->next = head2;
        head2->next = nxt1;

        cur = nxt1;
        head2 = nxt2;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

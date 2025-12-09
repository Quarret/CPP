#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

bool isPalindrome(ListNode* head) {
    vector<int> a;
    auto cur = head;
    while (cur) {
        a.push_back(cur->val);
        cur = cur->next;
    }

    vector<int> b(a.begin(), a.end());
    reverse(b.begin(), b.end());

    return a == b;
}

// 寻找中间节点 + 反转链表
bool isPalindrome(ListNode* head) {
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
    while (head2) {
        if (head->val != head2->val) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

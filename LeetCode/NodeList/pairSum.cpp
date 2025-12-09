#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

int pairSum(ListNode* head) {
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

    int ans = 0;
    while (head2) {
        ans = max(ans, head->val + head2->val);
        head = head->next;
        head2 = head2->next;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

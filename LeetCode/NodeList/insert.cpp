#include <bits/stdc++.h>
#include "Node.h"
using ll = long long;
using namespace std;

Node* insert(Node* head, int insertVal) {
    if (head == nullptr) {
        head = new Node(insertVal, nullptr);
        head->next = head;
        return head;
    }

    if (head->next = head) {
        head->next = new Node(insertVal, head);
        return head;
    }

    auto cur = head;
    int flag = 0, minn = 1e9;
    while (1) {
        if (cur == head) {
            if (flag == 1) break;
            flag = 1;
        }

        
    }
}

Node* insert(Node* head, int insertVal) {
    if (head == nullptr) {
        head = new Node(insertVal, nullptr);
        head->next = head;
        return head;
    }
    
    auto cur = head;
    while (cur->next != head) {
        // if (cur->next->val < cur->val) {
        //     if (cur->next->val >= insertVal) break;
        //     else if (cur->val <= insertVal) break;
        // }

        // if (cur->val <= insertVal && insertVal <= cur->next->val) break;
        if ((cur->next->val >= cur->val) ^ (cur->val <= insertVal) ^ (insertVal <= cur->next->val)) break;
        cur = cur->next;
    }
    cur->next = new Node(insertVal, cur->next);

    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

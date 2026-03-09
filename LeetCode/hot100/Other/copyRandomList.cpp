#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    // 添加这个构造函数
    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node* copyRandomList(Node* head) {
    // 复制链表, 每个节点后复制本省
    for (Node* cur = head; cur; cur = cur->next->next) {
        cur->next = new Node(cur->val, cur->next, nullptr);
    }

    // 交错链表, 新节点的 random 连到原 random 的新节点
    for (Node* cur = head; cur; cur = cur->next->next) {
        if (cur->random) {
            cur->next->random = cur->random->next;
        }
    }

    // 交错提取链表, 只留新节点
    Node dummy(0);
    Node* tail = &dummy;
    for (Node* cur = head; cur; cur = cur->next, tail = tail->next) {
        Node* copy = cur->next; // A 对应新节点 A'
        tail->next = copy;
        cur->next = copy->next; // 恢复原链接 A -> B
    }

    return dummy.next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
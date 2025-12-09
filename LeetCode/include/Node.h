#ifndef NODE_H
#define NODE_H

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

#endif // NODE_H

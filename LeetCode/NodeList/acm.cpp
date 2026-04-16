#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Node {
    int val;
    Node* next;

    Node() : val (0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node dummy(0);
    auto cur = &dummy;

    for (int i = 1; i <= 6; i++) {
        cur = cur->next = new Node(i);
    }
    
    cur = &dummy;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next; 
    }

    return 0;
}
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

class MyLinkedList {
private:
    ListNode *dummy;
    ListNode *tail;
    int size;

public:
    MyLinkedList() {
        dummy = new ListNode(0, nullptr);
        tail = dummy;
        size = 0;        
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        
        auto cur = dummy->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        dummy->next = new ListNode(val, dummy->next);
        if (tail->next) tail = tail->next;
        size++;
    }
    
    void addAtTail(int val) {
        tail->next = new ListNode(val, tail->next);
        tail = tail->next;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;

        auto cur = dummy;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->next = new ListNode(val, cur->next);
        if (index == size) tail = cur->next;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        auto cur = dummy;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        if (cur->next == tail) tail = cur;
        cur->next = cur->next->next;
        size--;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

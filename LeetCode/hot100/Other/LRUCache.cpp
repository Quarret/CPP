#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 库函数
class LRUCache {
    int capacity;
    list<pair<int, int>> cache_list; // 双向链表
    unordered_map<int, list<pair<int, int>>::iterator> key_to_iter; // key 对应 list 中的迭代器
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto umap_iter = key_to_iter.find(key);
        if (umap_iter == key_to_iter.end()) { // 没有这本书
            return -1;
        }

        auto list_iter = umap_iter->second; // 这本书在 list 中的迭代器
        // 将书 list_iter 抽出来放在 书堆 cache_list 顶部 cache_list.begin()
        cache_list.splice(cache_list.begin(), cache_list, list_iter);
        return list_iter->second; // 返回书的值
    }
    
    void put(int key, int value) {
        auto umap_iter = key_to_iter.find(key);
        if (umap_iter != key_to_iter.end()) { // 有这本书
            auto list_iter = umap_iter->second;
            list_iter->second = value; // 更新值
            // 将书 list_iter 抽出来放在 书堆 cache_list 顶部 cache_list.begin()
            cache_list.splice(cache_list.begin(), cache_list, list_iter);
            return;
        }

        // 新书
        cache_list.emplace_front(key, value);
        key_to_iter[key] = cache_list.begin();
        // 书太多了
        if (key_to_iter.size() > capacity) {
            key_to_iter.erase(cache_list.back().first);
            cache_list.pop_back();
        }
    }
};


// 手写双向链表
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), value(v) {} 
};

class LRUCache {
public:
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_node;

    // 删除节点 (抽书)
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    
    // 在链表头添加一个节点 (把一本书放在最上面)
    void push_front(Node* x) {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    // 获取 key 对应的节点, 并把 node 放到链表头部
    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) {
            return nullptr;
        }
        Node* node = it->second;
        remove(node);
        push_front(node);
        return node;
    }


    LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
        dummy->prev = dummy;
        dummy->next = dummy;
    }
    
    int get(int key) {
        Node* node = get_node(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        Node* node = get_node(key);
        if (node) {
            node->value = value;
            return;
        }
 
        key_to_node[key] = node = new Node(key, value); // 新书
        push_front(node); // 放在书堆顶部
        if (key_to_node.size() > capacity) { // 书太多
            Node* back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node); // 去掉最后一本书
            delete back_node;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
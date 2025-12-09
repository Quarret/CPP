#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// STL库
class LRUCache {
private:
    int Capacity;
    list<pair<int, int>> cache_list;
    unordered_map<int, list<pair<int, int>>::iterator> key_to_iter;
public:
    LRUCache(int capacity) {
        Capacity = capacity;
    }
    
    int get(int key) {
        auto umap_iter = key_to_iter.find(key);
        if (umap_iter == key_to_iter.end()) return -1;

        // 有书
        auto list_iter = umap_iter->second;
        // 将书(list_iter)抽出来, 放在书堆(cache_list)顶部(cache_list.begin())
        cache_list.splice(cache_list.begin(), cache_list, list_iter);
        return list_iter->second;
    }
    
    void put(int key, int value) {
        auto umap_iter = key_to_iter.find(key);
        if (umap_iter != key_to_iter.end()) {
            auto list_iter = umap_iter->second;
            list_iter->second = value;// 更新value

            // 将书(list_iter)抽出来, 放在书堆(cache_list)顶部(cache_list.begin())
            cache_list.splice(cache_list.begin(), cache_list, list_iter);
            return;
        }

        // 新书, 凡在书堆顶部(emplace_front)
        cache_list.emplace_front(key, value);
        key_to_iter[key] = cache_list.begin();

        // 书太多
        if (cache_list.size() > Capacity) {
            // 去掉书堆最后一本书
            key_to_iter.erase(cache_list.back().first);
            cache_list.pop_back();
        }
    }
};

// 手写双向链表
struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k = 0, int v = 0) {
        key = k;
        value  = v;
    }
};

class LRUCache {
private:
    int Capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_node;

    // 删除节点 (抽书)
    void remove(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    // 在链表头添加一个节点 (将书放在顶部)
    void push_front(Node *x) {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    // 根据 key 抽出书放在书堆顶部
    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) {
            return nullptr;
        }

        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }

public:
    LRUCache(int capacity) {
        Capacity = capacity;
        dummy = new Node();
        dummy->next = dummy;
        dummy->prev = dummy;
    }
    
    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        auto node = get_node(key);
        if (node) {
            node->value = value;
            return;
        }

        key_to_node[key] = node = new Node(key, value);
        push_front(node);
        if (key_to_node.size() > Capacity) {
            // 最后一本书
            auto back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node); // 删除最后一本书
            delete back_node; // 释放内存
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

#include <bits/stdc++.h>
using ll = long long;
using namespace std;


struct Node {
    Node* son[26]{};
    bool end = false;
};

class Tries {
    Node* root = new Node();
    
    int find(string word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (!cur->son[c]) {
                return 0;
            }
            cur = cur->son[c];
        }

        return cur->end ? 2 : 1;
    }

    void destroy(Node* node) {
        if (!node) {
            return;
        }

        for (Node* son : node->son) {
            destroy(son);
        }
        delete node;
    }

public:
    // 析构函数, 生命周期结束时释放内存
    ~Tries() {
        destroy(root);
    }

    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (!cur->son[c]) {
                cur->son[c] = new Node();
            }
            cur = cur->son[c];
        }
        cur->end = true;
    }

    bool search(string word) {
        return find(word) == 2;
    }

    bool startsWith(string pre) {
        return find(pre) != 0;
    }
};

class Solution {
public:
    vector<string> partitionString(string s) {
        Tries tries;

        string t;
        vector<string> ans;        
        for (char c : s) {
            t.push_back(c);
            if (!tries.startsWith(t)) {
                ans.push_back(t);
                tries.insert(t);
                t.clear();
            }
        }

        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Node {
    Node* son[26]{};
    bool end = false;
    int idx = -1;
};

class Tries {
    Node* root = new Node();
public:
    void insert(string word, int x) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (!cur->son[c]) {
                cur->son[c] = new Node();
            }
            cur = cur->son[c];
        }
        cur->end = true;
        cur->idx = x;
    }

    int search(string word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr) {
                break;
            }
            cur = cur->son[c]; // 先移动指针, 再比较终点

            if (cur->end) {
                return cur->idx;
            }
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    Tries tries;
    for (int i = 0; i < dictionary.size(); i++) {
        tries.insert(dictionary[i], i);
    }

    sentence.push_back(' ');
    string s, ans;
    for (char c : sentence) {
        if (c == ' ') {
            int idx = tries.search(s);
            string t = idx == -1 ? s : dictionary[idx];
            t.push_back(' ');
            ans += t;
            s.clear();
        } else s.push_back(c);
    }

    ans.pop_back();
    return ans;
    }    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
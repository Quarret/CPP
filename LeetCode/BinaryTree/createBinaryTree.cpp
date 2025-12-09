#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> mp;
    unordered_map<int, int> indeg;

    for (auto &e : descriptions) {
        int fa = e[0], child = e[1], isLeft = e[2];
        if (!mp[fa]) mp[fa] = new TreeNode(fa);
        if (!mp[child]) mp[child] = new TreeNode(child);
        (isLeft ? mp[fa]->left : mp[fa]->right) = mp[child];
        indeg[child]++;
    }

    int val = 0;
    for (auto &e : descriptions) {
        int fa = e[0];
        if (!indeg[fa]) {
            val = fa;
            break;
        }
    }
    return mp[val];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

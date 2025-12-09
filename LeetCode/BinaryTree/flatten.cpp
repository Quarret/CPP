#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

// 头插法
// 对每一个节点来插
TreeNode* head;
void flatten(TreeNode* root) {
    if (!root) {
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->left = nullptr;
    root->right = head;
    head = root;
}

// 分治
TreeNode* dfs(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    auto l_tail = dfs(root->left);
    auto r_tail = dfs(root->right);

    if (l_tail) {
        l_tail->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }

    // 一颗树先序遍历的尾. 若右尾不为空, 则右尾为尾; 若右尾为空, 则左尾为尾 
    return r_tail ? r_tail : (l_tail ? l_tail : root);
}
void flatten(TreeNode* root) {
    dfs(root);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

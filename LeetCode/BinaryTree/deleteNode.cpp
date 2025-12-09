#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* head = new TreeNode(10005, root, nullptr);

    auto f = [&](this auto&& f, TreeNode* root) -> int {
        if (!root) return 0;

        int val = root->val, change = 0;
        if (root->right) {
            change = f(root->right);
            if (!root->right->left && !root->right->right) {
                root->right = nullptr;
            }
        } else if (root->left) {
            change = f(root->left);
            if (!root->left->left && !root->left->right) {
                root->left = nullptr;
            }
        }

        root->val = change;
        return val;
    };

    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) return;

        if (root->val == key) {
            f(root);
            return;
        }
        if (root->val > key) dfs(root->left);
        if (root->val < key) dfs(root->right);
    };

    dfs(head);
    return head->left;
}

pair<int, TreeNode*> f(TreeNode* root) {
    if (!root) return {0, nullptr};
    if (!root->left && !root->right) {
        return {root->val, nullptr};
    }

    int val = root->val;
    auto [change, child] = root->right ? f(root->right) : f(root->left);
    (root->right ? root->right : root->left) = child;

    root->val = change;
    return {val, root};
};
TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* head = new TreeNode(10005, root, nullptr);

    auto dfs = [&](this auto&& dfs, TreeNode* root, TreeNode* fa, int isLeft) -> void {
        if (!root) return;

        if (root->val == key) {
            auto [val, child] = f(root);
            if (!child) (isLeft ? fa->left : fa->right) = child;
            return;
        }
        if (root->val > key) dfs(root->left, root, 1);
        if (root->val < key) dfs(root->right, root, 0);
    };

    dfs(head->left, head, 1);
    return head->left;
}


TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    // 左右搜索key
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {

        // 无左子树, 右子树顶替
        if (!root->left) return root->right;

        // 无右子树, 左子树顶替
        if (!root->right) return root->left;

        // 左右子树都存在, 将左子树接到右子树最左节点的左子树上
        auto node = root->right;
        while (node->left) {
            node = node->left;
        }
        node->left = root->left;

        // 右子树替换删除节点
        root = root->right;
    }

    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

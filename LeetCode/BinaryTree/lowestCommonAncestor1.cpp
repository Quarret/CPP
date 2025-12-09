#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 空节点返回空
    if (!root) return nullptr;

    // 当前节点就是p和q其中一个, 直接返回当前节点, 为什么? 假设p是当前节点
    // 假设 q 在 p 的左右子树中, 那么lca就是p
    // 假设 q 不在 p 的左右子树中, 那么接着遍历左右子树也没作用
    if (root->val == p->val || root->val == q->val) {
        return root;
    }

    // 记录左右子树搜索结果
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    // 如果左右子树都发现一个目标节点在其中, 那么lca就是root
    if (left && right) return root;

    // p 和 q在同一颗树的情况
    if (left) return left;

    // 这里将左右子树都没找到 和 在右子树中找到这两种情况合并了
    return right;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

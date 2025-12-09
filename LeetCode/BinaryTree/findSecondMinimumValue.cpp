#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

int findSecondMinimumValue(TreeNode* root) {
    set<int> st;

    auto f = [&](this auto&& f, TreeNode* root) -> void {
        if (!root) return;

        st.insert(root->val);
        f(root->left);
        f(root->right);
    };

    f(root);
    for (int x : st) {
        if (x != root->val) return x;
    }

    return -1;
}

int findSecondMinimumValue(TreeNode* root) {
    if (!root || !root->left || !root->right) return -1;
    
    int left = root->left->val, right = root->right->val;

    // 左子树的第二小的值
    if (left == root->val) left = findSecondMinimumValue(root->left);

    // 右子树第二小的值
    if (right == root->val) right = findSecondMinimumValue(root->right);

    // 左右第二小与最小相同
    if (left == right && root->val == left) return -1;

    // 选出root, left, right中的第二小, 即子树的第二小
    int minn = min(left, right);
    if (minn > root->val) return minn;
    else return max(left, right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

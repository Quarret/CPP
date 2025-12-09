#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

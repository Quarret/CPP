#include <bits/stdc++.h>
#include "TreeNode.h"
using i64 = long long;
using namespace std;

class CBTInserter {
    TreeNode* Root;
    queue<TreeNode*> Q;
public:
    CBTInserter(TreeNode* root) {
        Root = root;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if (!node->left || !node->right) Q.push(node);
            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }
    }
    
    int insert(int val) {
        auto node = Q.front();
        TreeNode* dummy = new TreeNode(val);
        Q.push(dummy);

        if (!node->left) {
            node->left = dummy;
        } else {
            node->right = dummy;
            Q.pop();
        }

        return node->val;
    }
    
    TreeNode* get_root() {
        return Root;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

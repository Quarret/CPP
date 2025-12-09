#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data) : data(data), left(nullptr), right(nullptr) {}
};

unordered_map<char, int> indexMap;

TreeNode* buildTree(const string& preorder, const string& inorder, int inStart, int inEnd, int preStart) {
    if (inStart > inEnd) {
        return nullptr;
    }

    char rootValue = preorder[preStart];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndex = indexMap[rootValue];

    root->left = buildTree(preorder, inorder, inStart, rootIndex - 1, preStart + 1);
    root->right = buildTree(preorder, inorder, rootIndex + 1, inEnd, preStart + (rootIndex - inStart + 1));

    return root;
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data;
}

void buildAndPrintPostorder(const string& preorder, const string& inorder) {
    indexMap.clear();
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
        indexMap[inorder[i]] = i;
    }

    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, 0);

    postorderTraversal(root);
    cout << endl;
}

// void solve() {
//     string preorder, inorder;
//     cin >> preorder;
//     cin >> inorder;
//     buildAndPrintPostorder(preorder, inorder);
// }
int main() {
    
    int n;
    while (1) {
        cin >> n;
        if (!n) {
            return 0;
        }
        string preorder, inorder;
        cin >> preorder;
        cin >> inorder;
        buildAndPrintPostorder(preorder, inorder);
    }
    
    

    return 0;
}

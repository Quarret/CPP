#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// DFS 方式构建二叉树 (前序遍历递归构建)
TreeNode* buildTreeDFS(const vector<int>& arr, int& idx, int nullVal = -1) {
    if (idx >= arr.size() || arr[idx] == nullVal) {
        idx++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(arr[idx++]);
    node->left = buildTreeDFS(arr, idx, nullVal);
    node->right = buildTreeDFS(arr, idx, nullVal);
    return node;
}

// 从层序遍历数组构建二叉树 (null 用 -1 或特定标记表示)
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // 构建左子树
        if (i < arr.size() && arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        // 构建右子树
        if (i < arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// 从输入流构建 (适合 ACM 输入格式)
TreeNode* buildFromInput() {
    int n;
    if (!(cin >> n)) return nullptr;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return buildTree(arr);
}

// 带自定义空值标记的构建
TreeNode* buildTreeWithNull(const vector<int>& arr, int nullVal = -1) {
    return buildTree(arr); // 复用主函数，-1 作为默认空值
}

// 层序遍历打印 (用于验证)
vector<int> levelOrder(TreeNode* root) {
    if (!root) return {};

    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            res.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            res.push_back(-1);
        }
    }

    // 移除末尾的 -1
    while (!res.empty() && res.back() == -1) res.pop_back();
    return res;
}

// 前序遍历构建 (适合 LeetCode 序列化格式)
TreeNode* buildFromPreorder(const vector<int>& preorder, int& idx, int nullVal = -1) {
    if (idx >= preorder.size() || preorder[idx] == nullVal) {
        idx++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[idx++]);
    node->left = buildFromPreorder(preorder, idx, nullVal);
    node->right = buildFromPreorder(preorder, idx, nullVal);
    return node;
}

// 从前序 + 中序构建
TreeNode* buildFromPreIn(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.empty()) return nullptr;

    unordered_map<int, int> pos;
    for (int i = 0; i < inorder.size(); i++) {
        pos[inorder[i]] = i;
    }

    function<TreeNode*(int, int, int, int)> dfs =
        [&](int pl, int pr, int il, int ir) -> TreeNode* {
        if (pl > pr || il > ir) return nullptr;

        TreeNode* root = new TreeNode(preorder[pl]);
        int k = pos[preorder[pl]];
        int leftSize = k - il;

        root->left = dfs(pl + 1, pl + leftSize, il, k - 1);
        root->right = dfs(pl + leftSize + 1, pr, k + 1, ir);
        return root;
    };

    return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
}

// 释放内存
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 方法 1: 层序遍历数组构建 [1,2,3,-1,-1,4,5] 表示:
    //       1
    //      / \
    //     2   3
    //        / \
    //       4   5
    vector<int> arr1 = {1, 2, 3, -1, -1, 4, 5};
    TreeNode* root1 = buildTree(arr1);

    // 方法 2: DFS 方式构建 (前序遍历顺序)
    // [1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1] 表示同样的树
    vector<int> arr2 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = 0;
    TreeNode* root2 = buildTreeDFS(arr2, idx);

    // 验证构建结果
    cout << "Level order (BFS build): ";
    auto result1 = levelOrder(root1);
    for (int x : result1) cout << x << " ";
    cout << "\n";

    cout << "Level order (DFS build): ";
    auto result2 = levelOrder(root2);
    for (int x : result2) cout << x << " ";
    cout << "\n";

    deleteTree(root1);
    deleteTree(root2);
    return 0;
}
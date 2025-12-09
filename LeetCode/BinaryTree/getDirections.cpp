#include <bits/stdc++.h>
#include "TreeNode.h"
using ll = long long;
using namespace std;

string getDirections(TreeNode* root, int startValue, int destValue) {
    auto dfs = [&](this auto&& dfs, TreeNode* root, string path) -> string {
        if (!root) return "";

        if (root->val == startValue) {
            return string('U', path.size());
        }
        if (root->val == destValue) {
            return path;
        }

        string left = dfs(root->left, path + 'L');
        string right = dfs(root->right, path + 'R');
        if (left != "" && right != "") {
            return left + right;
        }
        if (left != "") return left;
        return right;
    };

    return dfs(root, "");
}

int s = 0, d = 0;
TreeNode* LCA = nullptr;
pair<string, bool> dfs(TreeNode* root, string path) {
    if (!root) return {"", 0};

    if (root->val == d && LCA->val != d) {
        return {path, false};
    }

    if (LCA->val != s && root->val == s) {
        return {path, true};
    }

    auto [l_path, l_s] = dfs(root->left, path + 'L');
    auto [r_path, r_s] = dfs(root->right, path + 'R');

    if (root == LCA) {
        if (root->val == s) {
            return {l_path + r_path, 1};
        }

        if (root->val == d) {
            return {string(max(l_path.size(), r_path.size()), 'U'), 0};
        }

        if (l_s) {
            return {string(l_path.size(), 'U') + r_path, 1};
        } else {
            return {string(r_path.size(), 'U') + l_path, 1};
        }
    }

    return {l_path + r_path, l_s || r_s};
}
string getDirections(TreeNode* root, int startValue, int destValue) {
    s = startValue, d = destValue;
    auto findLCA = [&](this auto&& findLCA, TreeNode* root) -> TreeNode* {
        if (!root) return nullptr;

        if (root->val == startValue || root->val == destValue) {
            return root;
        }

        auto left = findLCA(root->left);
        auto right = findLCA(root->right);
        if (left && right) return root;
        if (left) return left;
        return right;
    };

    auto lca = findLCA(root);
    LCA = lca;
    string ans = dfs(lca, "").first;

    return ans;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    string path = "";
    
    auto dfs = [&](this auto&& dfs, TreeNode* root, int target) -> bool {
        if (!root) {
            return false;
        }

        if (root->val == target) {
            return true;
        }

        path += 'L';
        if (dfs(root->left, target)) {
            return true;
        }

        path.back() = 'R';
        if (dfs(root->right, target)) {
            return true;
        }

        path.pop_back();
        return false;
    };

    dfs(root, startValue);
    string path_to_start = path;
    path.clear();

    dfs(root, destValue);
    string path_to_dest = path;

    int i = 0;
    while (i < min(path_to_start.size(), path_to_dest.size()) && path_to_start[i] == path_to_dest[i]) {
        i++;
    }

    // start: "LLLL" dest: "LLRL"
    return string(path_to_start.size() - i, 'U') + path_to_dest.substr(i); 
}

// 一次DFS
string getDirections(TreeNode* root, int startValue, int destValue) {
    string path = "";
    string path_to_dest = path;
    string path_to_start = path;
    
    auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
        if (!root) {
            return;
        }

        if (root->val == startValue) {
            path_to_start = path;
        }

        if (root->val == destValue) {
            path_to_dest = path;
        }

        path += 'L';
        dfs(root->left);

        path.back() = 'R';
        dfs(root->right);

        path.pop_back();
    };

    dfs(root);

    int i = 0;
    while (i < min(path_to_start.size(), path_to_dest.size()) && path_to_start[i] == path_to_dest[i]) {
        i++;
    }

    // start: "LLLL" dest: "LLRL"
    return string(path_to_start.size() - i, 'U') + path_to_dest.substr(i); 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}

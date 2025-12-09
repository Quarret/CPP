#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    char c = NULL;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(char x) {
        c = x;
    }
};

TreeNode* build(vector<char>& preorder, vector<char>& inorder,
        int& prev, int inbegin, int inend)
{	//perorder 前序遍历序列，inorder 中序遍历序列,prev 指向前序遍历数列下标
        if (inbegin > inend)return NULL;
        //当前的根节点
        TreeNode* root = new TreeNode(preorder[prev]);
        int rooti = inbegin; //用来查找根节点在数组中的下班位置
        while (rooti < inend)
        {
            if (inorder[rooti] == preorder[prev])break;
            rooti++;
        }
        prev++;  //每次使用完prev需往后走，prev指的是数组前序遍历中用来判断根节点的
        //划分区间，（左子树，根）根（根，右子树）
        // （inbegin,rooti-1）rooti（rooti+1,inend）
        //函数递归继续构造二叉树的左右节点
        root->left = build(preorder, inorder, prev, inbegin, rooti - 1);
        root->right = build(preorder, inorder, prev, rooti + 1, inend);
        return root;
}

TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder) {
        int i = 0;
        TreeNode* root = build(preorder, inorder, i, 0, inorder.size() - 1);
        return root;
}

void suf(TreeNode* root) {
    if (root != NULL) {
        suf(root->left);
        suf(root->right);
        cout << root->c;
    }
}
int main() {
     
    while (1) {
        int n;
        cin >> n;
        vector<char> a, b;
        

        if (!n) {
            return 0;
        }

        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < n; i++) {
            a.push_back(s1[i]);
            b.push_back(s2[i]);
        }

        TreeNode* root1;
        root1 = buildTree(a, b);

        suf(root1);
        cout << '\n';
        
    }
}

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
private:
    unordered_map<int,int> mp;
    TreeNode* recur(vector<int>& preorder, int leftPre,int rightPre,vector<int>& inorder,int leftIn,int rightIn){
        //边界
        if(leftPre>rightPre) return nullptr;

        //记录左子树的长度
        int leftLen=mp[preorder[leftPre]]-leftIn;

        //执行
        TreeNode* node=new TreeNode(preorder[leftPre]);
        node->left=recur(preorder,leftPre+1,leftPre+leftLen,inorder,leftIn,leftIn+leftLen-1);
        node->right=recur(preorder,leftPre+leftLen+1,rightPre,inorder,leftIn+leftLen+1,rightIn);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //前序：根左右 中序：左根右；
        //先在中序中找出根结点，然后分出左子树和右子树的长度，然后递归构造二叉树
        int len=preorder.size();
        for(int i=0;i<inorder.size();++i) mp[inorder[i]]=i;
        return recur(preorder,0,len-1,inorder,0,len-1);
    }
};

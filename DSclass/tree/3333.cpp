
class Solution {
public:
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,
                        int& prev,int inbegin,int inend)
    {	//perorder 前序遍历序列，inorder 中序遍历序列,prev 指向前序遍历数列下标
        if(inbegin>inend)return NULL;
        //当前的根节点
        TreeNode* root=new TreeNode(preorder[prev]);
        int rooti=inbegin; //用来查找根节点在数组中的下班位置
        while(rooti<inend)
        {
            if(inorder[rooti]==preorder[prev])break;
            rooti++;
        }
        prev++;  //每次使用完prev需往后走，prev指的是数组前序遍历中用来判断根节点的
        //划分区间，（左子树，根）根（根，右子树）
        // （inbegin,rooti-1）rooti（rooti+1,inend）
        //函数递归继续构造二叉树的左右节点
        root->left=build(preorder,inorder,prev,inbegin,rooti-1); 
        root->right=build(preorder,inorder,prev,rooti+1,inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        TreeNode* root=build(preorder,inorder,i,0,inorder.size()-1);
        return root;
    }
};

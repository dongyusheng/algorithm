/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
            return NULL;

        // 递归开始判断
        return buildTreeCore(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *buildTreeCore(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        // 构造当前节点
        TreeNode *root = new TreeNode(preorder[preStart]);
        int rootValue = root->val;

        // 如果当前是最后一个节点了, 直接返回
        if (preStart == preEnd)
        {
            if (inStart == inEnd && preorder[preStart] == inorder[inStart])
                return root;
        }

        // 在中序遍历中找到根节点的值
        int index = inStart;
        while (inorder[index] != rootValue)
            index++;

        // 得到左子树的长度
        int leftLength = index - inStart;

        // 递归遍历左子树
        if (leftLength > 0)
            root->left = buildTreeCore(preorder, inorder, preStart + 1, preStart + leftLength - 1, inStart, inStart + leftLength - 1);
        // 递归遍历右子树
        if (index < inEnd)
            root->right = buildTreeCore(preorder, inorder, preStart + 1 + leftLength, preEnd, index + 1, inEnd);

        return root;
    }
};
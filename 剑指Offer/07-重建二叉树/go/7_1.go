package tree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) <= 0 || len(inorder) <= 0 {
		return nil
	}

	return _buildTree(preorder, inorder, 0, len(preorder)-1, 0, len(inorder)-1)
}

// 递归实现
func _buildTree(preorder []int, inorder []int, preStart, preEnd, inStart, inEnd int) *TreeNode {
	rootValue := preorder[preStart]

	// 前序遍历的第一个节点就是根节点
	root := &TreeNode{
		Val: rootValue,
	}

	// 如果当前只有一个节点了
	if preStart == preEnd {
		if inStart == inEnd && preorder[preStart] == inorder[inStart] {
			return root
		}
	}

	// 在中序遍历中找到根节点的位置
	rootValueInInOrder := inStart
	for ; inorder[rootValueInInOrder] != rootValue && rootValueInInOrder <= inEnd; rootValueInInOrder++ {
	}

	// 左子节点的数量
	leftCount := rootValueInInOrder - inStart

	// 递归构建左子结点
	if leftCount > 0 {
		root.Left = _buildTree(preorder, inorder, preStart+1, preStart+leftCount, inStart, rootValueInInOrder-1)
	}

	// 递归构建右子节点
	if rootValueInInOrder < inEnd {
		root.Right = _buildTree(preorder, inorder, preStart+leftCount+1, preEnd, rootValueInInOrder+1, inEnd)
	}

	// 返回当前根节点
	return root
}

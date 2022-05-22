package tree

/*
type TreeLinkNode struct {
    Val int
    Left *TreeLinkNode  // 左子结点
    Right *TreeLinkNode // 右子节点
    Next *TreeLinkNode  // 父节点
}
*/

func GetNext(pNode *TreeLinkNode) *TreeLinkNode {
	// 如果有右子节点
	if pNode.Right != nil {
		// 一直遍历, 返回右子节点中最左侧节点
		resultNode := pNode.Right
		for resultNode.Left != nil {
			resultNode = resultNode.Left
		}

		return resultNode
	} else if pNode.Next != nil {
		// 无右子节点, 但是有父节点
		currentNode := pNode
		parentNode := pNode.Next

		for parentNode != nil && currentNode == parentNode.Right {
			// 父节点不为空, 同时当前节点是父节点的右子节点, 一直向上找
			currentNode = parentNode
			parentNode = currentNode.Next
		}

		return parentNode
	}

	return nil
}

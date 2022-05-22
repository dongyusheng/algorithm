package list

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
	// 使用slice模仿堆的用法
	stack := make([]int, 0)

	// 入栈
	for ; head != nil; head = head.Next {
		stack = append(stack, head.Val)
	}
	index := len(stack) - 1
	result := make([]int, 0)
	// 出栈打印
	for ; index >= 0; index-- {
		result = append(result, stack[index])
	}

	return result
}

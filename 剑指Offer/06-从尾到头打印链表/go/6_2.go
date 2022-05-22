package list

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
	result := make([]int, 0)
	return _reversePrint(result, head)
}

func _reversePrint(result []int, head *ListNode) []int {
	if head != nil {
		result = _reversePrint(result, head.Next)
	}

	if head == nil {
		return result
	}

	result = append(result, head.Val)
	return result
}

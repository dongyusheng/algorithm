package search

// 查找最后一个值等于给定值的元素, 要求：
// 1.元素已经从小到大排序好
// 2.数组中有重复的元素

func bsearchLastEqual(a []int, len, value int) int {
	low := 0
	high := len - 1

	for low <= high {
		mid := low + ((high - low) >> 1)

		if a[mid] > value {
			high = mid - 1
		} else if a[mid] < value {
			low = mid + 1
		} else {
			if mid == 0 || a[mid+1] != value {
				return mid
			} else {
				low = mid + 1
			}
		}
	}

	return -1
}

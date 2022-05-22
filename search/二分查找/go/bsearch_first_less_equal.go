package search

// 查找最后一个小于等于给定值的元素, 要求：
// 1.元素已经从小到大排序好
// 2.数组中有重复的元素

func bsearchFirstLessEqual(a []int, len, value int) int {
	low := 0
	high := len - 1

	for low <= high {
		mid := low + ((high - low) >> 1)

		if a[mid] <= value {
			if mid == 0 || a[mid-1] > value {
				return mid
			} else {
				high = mid - 1
			}
		} else {
			low = mid + 1
		}
	}

	return -1
}

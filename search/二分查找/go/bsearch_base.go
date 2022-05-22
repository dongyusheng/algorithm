package search

// 最基本的二分查找, 条件:
// 1.元素已经从小到大排序好
// 2.数组中没有重复的元素

// 非递归实现
func bsearch(a []int, len int, value int) int {
	low := 0
	high := len - 1

	for low <= high {
		mid := low + ((high - low) >> 1)

		if a[mid] > value {
			// 大于要查找的值
			high = mid - 1
		} else if a[mid] < value {
			low = mid + 1
		} else {
			return mid
		}
	}

	return -1
}

// 递归实现
func bsearchRecurSion(a []int, len int, value int) int {
	return _bsearchRecurSion(a, value, 0, len-1)
}

func _bsearchRecurSion(a []int, value, low, high int) int {
	if low > high {
		return -1
	}

	mid := low + ((high - low) >> 1)

	if a[mid] == value {
		return mid
	} else if a[mid] > value {
		return _bsearchRecurSion(a, value, low, mid-1)
	} else {
		return _bsearchRecurSion(a, value, mid+1, low)
	}
}

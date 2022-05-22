package array

// 哈希表的方式, 时间复杂度O(n)
// 不过由于使用了map, 多了额外的O(n)空间复杂度
func findRepeatNumber(nums []int) int {
	tmpMap := make(map[int]struct{}, len(nums))

	for _, value := range nums {
		// 在map中已经存在
		_, ok := tmpMap[value]
		if ok {
			return value
		}

		// 否则存入map
		tmpMap[value] = struct{}{}
	}

	return -1
}

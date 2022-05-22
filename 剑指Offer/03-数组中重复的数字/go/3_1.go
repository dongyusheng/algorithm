package array

// 时间复杂度O(n^2)
func findRepeatNumber(nums []int) int {
	for index := 0; index < len(nums); index++ {
		// nums[index]的值与索引不相等, 就一直交换
		for nums[index] != index {
			// 如果出现与对应index相同的情况, 说明重复了
			if nums[index] == nums[nums[index]] {
				return nums[index]
			}

			// 否则交换数据继续比较
			nums[nums[index]], nums[index] = nums[index], nums[nums[index]]
		}
	}

	return -1
}

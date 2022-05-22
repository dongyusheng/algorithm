package num

func minArray(numbers []int) int {
	leftIndex := 0
	rightIndex := len(numbers) - 1
	resultIndex := leftIndex

	for numbers[leftIndex] >= numbers[rightIndex] {
		// 如果两个索引相邻, 则rightIndex是最小的
		if leftIndex == rightIndex-1 {
			resultIndex = rightIndex
			break
		}

		midIndex := (rightIndex + leftIndex) / 2

		// 特殊情况处理: 三个索引对应的值全是相同的, 遍历查找
		if numbers[leftIndex] == numbers[rightIndex] &&
			numbers[leftIndex] == numbers[midIndex] {
			resultIndex = minIndexInNumbers(numbers, leftIndex, rightIndex)
			break
		} else if numbers[leftIndex] <= numbers[midIndex] {
			// 左侧索引逻辑处理
			leftIndex = midIndex
		} else if numbers[rightIndex] >= numbers[midIndex] {
			// 右侧索引逻辑处理
			rightIndex = midIndex
		}
	}

	return numbers[resultIndex]
}

func minIndexInNumbers(numbers []int, startIndex, endIndex int) int {
	minIndex := startIndex
	for index := startIndex; index <= endIndex; index++ {
		if numbers[index] < numbers[minIndex] {
			minIndex = index
		}
	}

	return minIndex
}

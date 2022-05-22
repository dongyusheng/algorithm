package array

func findNumberIn2DArray(matrix [][]int, target int) bool {
	// 边界处理
	if len(matrix) <= 0 || len(matrix[0]) <= 0 {
		return false
	}

	// 行数与列数
	rowIndex := 0
	colIndex := len(matrix[0]) - 1
	rowCount := len(matrix)

	// 从右上角开始遍历
	for rowIndex < rowCount && colIndex >= 0 {
		if matrix[rowIndex][colIndex] == target {
			return true
		}

		// 比目标值小, 排除该行
		if matrix[rowIndex][colIndex] < target {
			rowIndex++
			continue
		}

		// 比目标值大, 排除该列
		if matrix[rowIndex][colIndex] > target {
			colIndex--
			continue
		}
	}

	return false
}

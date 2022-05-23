package main

import "fmt"

const (
	queensCount = 8 // 皇后数量
)

var count int // 八皇后问题解法总数

func main() {
	// 下标索引表示行, 数组的值表示列
	result := make([]int, queensCount)

	cal8Queens(result, 0)

	fmt.Printf("count:%d\n", count)
}

// 计算八皇后
func cal8Queens(result []int, row int) {
	// 全部放完了
	if row == queensCount {
		count++
		printQueens(result)
		return
	}

	// 每一行有8种放置的方法
	for col := 0; col < queensCount; col++ {
		// 满足放置要求
		if isOk(result, row, col) {
			result[row] = col         // 第row行的皇后放到了第col列
			cal8Queens(result, row+1) // 进入下一行
		}
	}
}

func isOk(result []int, row, col int) bool {
	leftUp := col - 1
	rightUp := col + 1

	// 逐行向上检测
	for i := row - 1; i >= 0; i-- {
		// 上方是否已经有皇后?
		if result[i] == col {
			return false
		}

		// 左上是否已经有皇后?
		if leftUp >= 0 && result[i] == leftUp {
			return false
		}

		// 右上是否已经有皇后?
		if rightUp < queensCount && result[i] == rightUp {
			return false
		}

		leftUp--
		rightUp++
	}

	return true
}

func printQueens(result []int) {
	for row := 0; row < queensCount; row++ {
		for col := 0; col < queensCount; col++ {
			if result[row] == col {
				fmt.Printf("Q ")
			} else {
				fmt.Printf("* ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

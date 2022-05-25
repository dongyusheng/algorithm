package main

// 去除了递归中重复值计算

import "fmt"

const (
	packCapacity = 9 // 背包最大容量
)

var currentMaxValue = 0 // 当前的最大值

func main() {
	goodsArray := []int{2, 2, 4, 6, 3}

	// 递归备忘录
	boolean := make([][]bool, 5)
	for i := range boolean {
		boolean[i] = make([]bool, 10)
	}

	maxValue(0, 0, goodsArray, len(goodsArray), packCapacity, boolean)
	fmt.Printf("currentMaxValue:%d\n", currentMaxValue)

	// currentMaxValue:9
}

// n: 当前是哪个物品; currentValue所有物品的总量
// goodsArray: 所有的物品列表(数组的值为物品的重量); goodsCount: 物品总数
// packCapacity: 背包的最大容量
func maxValue(n int, currentValue int, goodsArray []int, goodsCount int, packCapacity int, boolean [][]bool) {
	// 寻找到最后一个物品了 || 背包已经满了
	if n == goodsCount || currentValue == packCapacity {
		if currentValue > currentMaxValue {
			currentMaxValue = currentValue
		}
		return
	}

	// 重复状态, 就不需要再访问了
	if boolean[n][currentValue] {
		return
	}

	boolean[n][currentValue] = true

	// 分支1: 将该物品不装进背包
	maxValue(n+1, currentValue, goodsArray, goodsCount, packCapacity, boolean)

	// 分支2: 将该物品装进背包(装进去之前先判断一下是否会超重)
	nValue := goodsArray[n]
	if currentValue+nValue <= packCapacity {
		maxValue(n+1, currentValue+nValue, goodsArray, goodsCount, packCapacity, boolean)
	}
}

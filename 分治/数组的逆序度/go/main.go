package main

import "fmt"

var num int

func main() {
	arr := []int{2, 4, 3, 1, 5, 6}
	fmt.Printf("before:%+v\n", arr)
	MergeSort(arr)
	fmt.Printf("after:%+v\n", arr)

	// 逆序对有4个, (2,1), (4,3), (4,1), (3,1)
	fmt.Printf("num:%d\n", num)
}

// 归并排序
func MergeSort(arr []int) {
	if len(arr) <= 1 {
		return
	}

	_merge_sort(arr, 0, len(arr)-1)
}

// 分治排序
func _merge_sort(arr []int, start, end int) {
	if start >= end {
		return
	}

	middle := (start + end) / 2

	_merge_sort(arr, start, middle)
	_merge_sort(arr, middle+1, end)
	_merge(arr, start, middle, end)
}

// 归并
func _merge(arr []int, left, middle, right int) {
	temp := make([]int, (right - left + 1))

	k := 0

	// 左右区间的起始索引
	leftIndex := left
	rightIndex := middle + 1

	// 遍历左右两个区间并比较
	for ; leftIndex <= middle && rightIndex <= right; k++ {
		if arr[leftIndex] <= arr[rightIndex] {
			temp[k] = arr[leftIndex]
			leftIndex++
		} else {
			temp[k] = arr[rightIndex]
			num += (middle - leftIndex + 1)
			rightIndex++
		}
	}

	// 将剩余元素拷贝进temp
	for ; leftIndex <= middle; leftIndex++ {
		temp[k] = arr[leftIndex]
		k++
	}
	for ; rightIndex <= right; rightIndex++ {
		temp[k] = arr[rightIndex]
		k++
	}

	// 更新信息
	copy(arr[left:right+1], temp)
}

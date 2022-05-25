package main

import "fmt"

func main() {
	arr := []int{11, 8, 3, 9, 7, 1, 2, 5}
	fmt.Printf("before:%+v\n", arr)
	QuickSort(arr)
	fmt.Printf("after:%+v\n", arr)

	// before:[11 8 3 9 7 1 2 5]
	// after:[1 2 3 5 7 8 9 11]
}

func QuickSort(arr []int) {
	if len(arr) <= 1 {
		return
	}

	separateSort(arr, 0, len(arr)-1)
}

func separateSort(arr []int, start, end int) {
	if start >= end {
		return
	}

	pivot := partition(arr, start, end)
	separateSort(arr, start, pivot-1)
	separateSort(arr, pivot+1, end)
}

func partition(arr []int, start, end int) int {
	pivotValue := arr[end]

	i := start
	for j := start; j <= end; j++ {
		if arr[j] < pivotValue {
			if j != i {
				arr[i], arr[j] = arr[j], arr[i]
			}
			i++
		}
	}

	arr[end], arr[i] = arr[i], pivotValue
	return i
}

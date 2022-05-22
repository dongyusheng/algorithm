package array

func fib(n int) int {
	if n <= 1 {
		return n
	}

	preValue := 0
	nextValue := 1
	result := 0

	for i := 2; i <= n; i++ {
		result = (preValue + nextValue) % 1000000007
		preValue = nextValue
		nextValue = result
	}

	return result
}

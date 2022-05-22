package main

import "strings"

func replaceSpace(s string) string {
	// 得到原先字符串中有多少个空格
	spaceCount := strings.Count(s, " ")

	// 分配一个辅助数组
	tmpBytes := make([]byte, len(s)+(spaceCount*2))

	// 指向原数组末尾
	iIndex := len(s) - 1
	// 指向辅助数组末尾
	jIndex := len(tmpBytes) - 1

	// 遍历原字符串
	for iIndex >= 0 {
		// 如果遇到了空格
		if s[iIndex] == ' ' {
			tmpBytes[jIndex] = '0'
			jIndex--
			tmpBytes[jIndex] = '2'
			jIndex--
			tmpBytes[jIndex] = '%'
			jIndex--
		} else {
			// 未遇到空格
			tmpBytes[jIndex] = s[iIndex]
			jIndex--
		}
		iIndex--
	}

	return string(tmpBytes)
}

package main

import "fmt"

type Pattern struct {
	// *: 匹配任意个字符(不包括0个)
	// ?: 匹配0个或1个字符

	pattern string // 正则表达式
	isMatch bool
}

func NewPattern(p string) *Pattern {
	return &Pattern{
		pattern: p,
	}
}

// 核心函数在这里
// pIndex: 正则表达式目前的遍历索引; tIndex: 传入文本目前的遍历索引
func (p *Pattern) Match(pIndex int, tIndex int, text string) {
	if p.isMatch {
		// 已经匹配完成
		return
	}

	// 正则表达式遍历完成
	if pIndex == len(p.pattern) {
		if tIndex == len(text) {
			// 文本也遍历完了
			p.isMatch = true
			return
		}
		return
	}

	if p.pattern[pIndex] == '*' {
		// 匹配任意个字符(不包括0个)
		for i := 0; i < (len(text) - tIndex); i++ {
			p.Match(pIndex+1, tIndex+i, text)
		}
	} else if p.pattern[pIndex] == '?' {
		// 匹配0个或1个字符
		p.Match(pIndex+1, tIndex, text)
		p.Match(pIndex+1, tIndex+1, text)
	} else if tIndex < len(text) && p.pattern[pIndex] == text[tIndex] {
		// 纯文字匹配
		p.Match(pIndex+1, tIndex+1, text)
	}
}

func (p *Pattern) GetPattern() string {
	return p.pattern
}

func main() {
	pattern1 := NewPattern("He*Worl?")
	match(pattern1, "HelloWorld")

	pattern2 := NewPattern("?ell?Wo*ld")
	match(pattern2, "HelloWorld")

	pattern3 := NewPattern("?e?Wo*ld")
	match(pattern3, "HelloWorld")

	// 	pattern: He*Worl?, text: HelloWorld, result: match
	// pattern: ?ell?Wo*ld, text: HelloWorld, result: match
	// pattern: ?e?Wo*ld, text: HelloWorld, result: un match
}

func match(pattern *Pattern, text string) {
	fmt.Printf("pattern: %s, text: %s, result: ", pattern.GetPattern(), text)
	pattern.Match(0, 0, text)
	if pattern.isMatch {
		fmt.Printf("match\n")
	} else {
		fmt.Printf("un match\n")
	}
}

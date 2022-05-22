package queue

type CQueue struct {
	// 使用两个slice模仿栈
	stack1 []int // 核心栈(起始: 栈尾; 结束: 栈顶)
	stack2 []int // 辅助栈(同上)
}

func Constructor() CQueue {
	return CQueue{}
}

func (this *CQueue) AppendTail(value int) {
	// 直接追加到核心栈顶部即可
	this.stack1 = append(this.stack1, value)
}

func (this *CQueue) DeleteHead() int {
	if len(this.stack2) <= 0 {
		if len(this.stack1) <= 0 {
			return -1
		}

		// 将核心栈中的内容全部拷贝到辅助栈中
		this.moveStackValue()
	}

	// 取走辅助栈顶元素, 并更新信息
	value := this.stack2[len(this.stack2)-1]
	this.stack2 = this.stack2[:len(this.stack2)-1]
	return value
}

func (this *CQueue) moveStackValue() {
	// 将核心栈中的内容从尾到头添加到辅助栈中
	for i := len(this.stack1) - 1; i >= 0; i-- {
		this.stack2 = append(this.stack2, this.stack1[i])
	}

	// 清空辅助栈
	this.stack1 = this.stack1[0:0]
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */

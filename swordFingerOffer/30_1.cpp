// https://blog.csdn.net/qq_41453285/article/details/108196817
#include <stack>
#include <assert.h>
#include <cstdio>

template <typename T> class StackWithMin
{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    const T& min() const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
    std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
    // 如果辅助栈为空, 或者新元素比辅助栈顶元素值小, 那么就把新元素加入到辅助栈了
    if(m_min.empty() || value < m_min.top())
        m_min.push(value);
    // 否则就把栈顶元素拷贝一份再加入到辅助栈中
    else
        m_min.push(m_min.top());

    // 将元素加入主栈
    m_data.push(value);
}

template <typename T>
void StackWithMin<T>::pop()
{
    // 判断两个栈是否有元素
    assert(m_data.size() > 0 && m_min.size() > 0);

    // 出栈即可
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
    // 判断两个栈是否有元素
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

template <typename T> T& StackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
    return m_data.size();
}

void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, char* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);

    return 0;
}

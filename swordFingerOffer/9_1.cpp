/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Dongshao
 * @Date: 2020-07-31 09:09:08
 * @LastEditors: Dongshao
 * @LastEditTime: 2020-08-17 10:21:25
 */

#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template<typename T>
class CQueue
{
public:
    CQueue(void) {}
    ~CQueue(void) {}

    void appendTail(const T& node);
    T deleteHead();
private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
    // 如果stack2中没有元素, 把stack1的所有元素拷贝到stack2中进行删除
    if(stack2.size() <= 0)
    {
        while(stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    // if如果没有执行, 说明stack2中有元素，直接删除即可

    // 如果stack2为空, 说明此时两个栈中都没有元素了
    if(stack2.size() <= 0)
        throw std::runtime_error("queue is empty");
    
    // 出栈
    T data = stack2.top();
    stack2.pop();
    return data;
}

int main()
{
    CQueue<int> *myQueue = new CQueue<int>;

    myQueue->appendTail(10);
    myQueue->appendTail(20);
    myQueue->appendTail(30);

    std::cout << myQueue->deleteHead() << std::endl;  // 10
    std::cout << myQueue->deleteHead() << std::endl;  // 20

    myQueue->appendTail(40);
    
    std::cout << myQueue->deleteHead() << std::endl;  // 30
    std::cout << myQueue->deleteHead() << std::endl;  // 40
    
    return 0;
}

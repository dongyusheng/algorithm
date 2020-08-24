// https://blog.csdn.net/qq_41453285/article/details/108197870
#include <cstdio>
#include <stack>

/**
 * @description: 
 * @param:
        pPush: 压栈序列
        pPop: 出栈序列
        nLength: 栈中的元素总数
 * @return {type} 
 * @author: Dongshao
 */
bool IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
    bool bPossible = false;

    if(pPush != nullptr && pPop != nullptr && nLength > 0)
    {
        // 得到两个栈的首元素
        const int *PnextPush = pPush;
        const int *pNextPop = pPop;

        // 辅助栈
        std::stack<int> stackData;

        // 逐个取出弹出序列栈中的元素
        while(pNextPop - pPop < nLength)
        {
            // 当辅助栈的栈顶元素不是要弹出的元素
            // 先压入一些数字入栈
            while(stackData.empty() || stackData.top() != *pNextPop)
            {
                // 如果所有数字都压入辅助栈了，退出循环
                if(PnextPush - pPush == nLength)
                    break;
                
                // 把压栈序列元素压入栈中
                stackData.push(*PnextPush);

                // 压栈序列向后移动继续判断
                PnextPush++;
            }

            // 栈顶元素与出栈序列的首元素不一样, 进行下一次循环
            if(stackData.top() != *pNextPop)
                break;
            
            // 否则, 将栈顶元素出栈, 然后出栈序列向后移动
            stackData.pop();
            pNextPop++;
        }

        // 如果栈是空的, 并且出栈序列中的所有元素都判断完了, 返回true
        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }

    return bPossible;
}

// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}
 
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

// https://blog.csdn.net/qq_41453285/article/details/108699935
#include <cstdio>

void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;
    
    int small = 1;
    int big = 2;

    // 查询的终止条件
    int middle = (1 + sum) / 2;
    // 当前的大小
    int curSum = small + big;

    while(small < middle)
    {
        // 当curSum等于sum时, 打印即可
        if(curSum == sum)
            PrintContinuousSequence(small, big);
        
        // 如果curSum大于sum, 那么将small向后移动
        while(curSum > sum && small < middle)
        {
            // curSum减去small, small向后移动
            curSum -= small;
            small++;

            // 如果相等了就打印
            if(curSum == sum)
                PrintContinuousSequence(small, big);
        }

        // 将big向后移动, curSum增加, 继续向后判断
        big++;
        curSum += big;
    }
}

void PrintContinuousSequence(int small, int big)
{
    for(int i = small; i <= big; ++i)
        printf("%d ", i);
    printf("\n");
}

// ====================测试代码====================
void Test(const char* testName, int sum)
{
    if(testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum);
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}

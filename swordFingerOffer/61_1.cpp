// https://blog.csdn.net/qq_41453285/article/details/108716511
#include <cstdlib>
#include <cstdio>

int compare(const void *arg1, const void *arg2);

bool IsContinuous(int* numbers, int length)
{
    if(numbers == nullptr || length < 1)
        return false;
    
    // 先把数组进行排序, 从大到小
    qsort(numbers, length, sizeof(int), compare);

    // 统计数组中0的个数
    int numberOfZero = 0;
    for(int i = 0; i < length && numbers[i] == 0; ++i)
        numberOfZero++;
    
    int numberOfGap = 0; // 表示数组相邻元素之间的空缺总数
    int small = numberOfZero; // 从0开始遍历
    int big = small + 1;      // 下一个数字
    
    // 统计数组中的间隔数目
    while(big < length)
    {
        // 特殊情况处理: 如果2个数字相等, 那么有对子, 不可能是顺子, 退出
        if(numbers[small] == numbers[big])
            return false;
        
        // 记录下2个数字之间的差距
        numberOfGap += (numbers[big] - numbers[small] - 1);

        // 更新索引
        small = big;
        big++;
    }

    // 如果numberOfGap > numberOfZero, 那么不能使用0进行填充, 返回fasle
    if(numberOfGap > numberOfZero)
        return false;
    return true;
}

int compare(const void *arg1, const void *arg2)
{
    return *(int*)arg1 - *(int*)arg2;
}


// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsContinuous(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int numbers[] = { 1, 3, 2, 5, 4 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
    int numbers[] = { 0, 3, 1, 6, 4 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
    int numbers[] = { 1, 3, 0, 5, 0 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
    int numbers[] = { 1, 3, 0, 7, 0 };
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
    int numbers[] = { 1, 0, 0, 5, 0 };
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
    int numbers[] = { 1, 0, 0, 7, 0 };
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
    int numbers[] = { 3, 0, 0, 0, 0 };
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
    int numbers[] = { 0, 0, 0, 0, 0 };
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
    Test("Test12", nullptr, 0, false);
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
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}

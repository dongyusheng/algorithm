// https://blog.csdn.net/qq_41453285/article/details/108284738
#include <cstdio>
#include <stdexcept>

using namespace std;

void BubbleSort(int *numbers, int length);

int MoreThanHalfNum(int *numbers, int length)
{
    if(numbers == nullptr || length <=0 )
        throw std::runtime_error("Input error.");
    
    // 先排序, 随便用什么方法排序, 此处使用的冒泡排序
    BubbleSort(numbers, length);

    // 存放某个数字出现的次数
    int count = 0;
    // 先从第一个元素开始判断
    int currentNum = numbers[0];

    // 遍历整个数组
    for(int i = 1; i < length; ++i)
    {
        if(numbers[i] == currentNum)
        {
            count++;
            // 如果这个元素的次数超过了数组的一半, 返回这个数字
            if(count > (length / 2))
                return currentNum;
        }
        else
        {
            currentNum = numbers[i];
            count = 1;
        }
    }
}

void BubbleSort(int *numbers, int length)
{
    for(int i = 0; i < length - 1; ++i)
    {
        for(int j = 0; j < length - 1 - i; ++j)
        {
            if(numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}


// ====================测试代码====================
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution: ");
    int result = MoreThanHalfNum(numbers, length);
    if(result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 只有一个数字
void Test5()
{
   int numbers[] = {1};
   Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}


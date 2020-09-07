//https://blog.csdn.net/qq_41453285/article/details/108284738
#include <iostream>
 
using namespace std;

// 检测number是否是numbers的中位数
bool CheckMoreThanHalf(int *numbers, int length, int number)
{
    int times = 0;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] == number)
            times++;
    }

    // 次数没有超过一半, 返回false
    if(times * 2 <= length)
        return false;

    return true;
}

int MoreThanHalfNum(int *numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return 0;
    
    int result = numbers[0];
    int count = 1;

    // 遍历数组
    for(int i = 1; i < length; ++i)
    {
        // 如果这数字与result不同
        if(numbers[i] != result)
        {
            // 减去次数
            count--;
            // 如果次数变为0了, 重新以这个数字开始计数
            if(count == 0)
            {
                result = numbers[i];
                count = 1;
            }
        }
        // 相等, 次数加1即可
        else if(numbers[i] == result)
            count++;
    }

    // 检测一下result是否正确
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    // 返回
    return result;
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

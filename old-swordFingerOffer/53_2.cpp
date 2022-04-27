// https://blog.csdn.net/qq_41453285/article/details/108623123
#include <cstdio>

int GetMissingNumber(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;
    
    int left = 0;
    int right = length - 1;

    int middle;
    while(left <= right)
    {
        middle = (left + right) / 2;
        
        // 如果下标与对应的数字不相等
        if(middle != numbers[middle])
        {
            // 如果坐标的数字与对应的下标相等, 或者左边没有元素了
            if(middle == 0 || numbers[middle - 1] == middle - 1)
                return middle;
            // 否则在左侧继续寻找
            else
                right = middle - 1;
        }
        // 如果下标与对应的数字相等, 那么在右侧寻找
        else
            left = middle + 1;
    }

    // 如果缺少的是最后一个数字
    if(left == length)
        return length;
    
    // 无效的输入, 或者数组不是按照要求排序的, 或者有数字不再0 ~ n - 1范围之内
    return -1;
}

// ====================测试代码====================
void Test(const char* testName, int numbers[], int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetMissingNumber(numbers, length);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 缺失的是第一个数字0
void Test1()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
    int expected = 0;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void Test2()
{
    int numbers[] = { 0, 1, 2, 3, 4 };
    int expected = 5;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void Test3()
{
    int numbers[] = { 0, 1, 2, 4, 5 };
    int expected = 3;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
    int numbers[] = { 1 };
    int expected = 0;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test5()
{
    int numbers[] = { 0 };
    int expected = 1;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void Test6()
{
    int expected = -1;
    Test("Test6", nullptr, 0, expected);
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

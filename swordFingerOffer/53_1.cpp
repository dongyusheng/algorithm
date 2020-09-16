// https://blog.csdn.net/qq_41453285/article/details/108623123
#include <cstdio>

int GetFistK(int *data, int length, int k, int start, int end)
{
    if(start > end)
        return -1;
    
    // 中间的索引
    int middleIndex = (start + end) / 2;

    // 如果中间元素与k相同
    if(data[middleIndex] == k)
    {
        // 如果中间位置前面还有元素, 并且与k不相同, 或者middleIndex前面没有数字了
        // 那么middleIndex就是元素k在数组中第一次出现的位置
        if((middleIndex > 0 && data[middleIndex - 1] != k ) || middleIndex == 0)
            return middleIndex;
        
        // 否则, 将end改为middleIndex - 1, 继续在数组前半段开始遍历
        end = middleIndex - 1;
    }
    // 如果中间元素比k大, 在数组前半段遍历
    else if(data[middleIndex] > k)
    {
        end = middleIndex - 1;
    }
    // 如果中间元素比k小, 在数组后半段遍历
    else
    {
        start = middleIndex + 1;
    }

    // 递归遍历数组
    return GetFistK(data, length, k, start, end);
}

int GetLastK(int *data, int length, int k, int start, int end)
{
    if(start > end)
        return -1;
    
    // 得到中间索引
    int middleIndex = (start + end) / 2;

    // 如果中间元素与k相同
    if(data[middleIndex] == k)
    {
        // 如果middleIndex后面的元素与k不相同, 或者middleIndex已经达到末尾了
        // 那么middleIndex就是元素k在数组中最后一次出现的位置
        if((middleIndex  < length - 1 && data[middleIndex + 1] != k) || middleIndex == end - 1)
            return middleIndex;
        
        // 否则, 将start改为middleIndex + 1, 继续在数组后半段开始遍历
        start = middleIndex + 1;
    }
    // 如果中间元素比k大, 在数组前半段遍历
    else if(data[middleIndex] > k)
    {
        end = middleIndex - 1;
    }
    // 如果中间元素比k小, 在数组后半段遍历
    else
    {
        start = middleIndex + 1;
    }

    return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int *data, int length, int k)
{
    int number = 0;

    if(data != nullptr && length > 0)
    {
        // 得到k的第一次出现索引
        int firstIndex = GetFistK(data, length, k, 0, length);
        // 得到k的最后一次出现索引
        int lastIndex = GetLastK(data, length, k, 0, length);

        if(firstIndex > -1 && lastIndex > -1)
            number = lastIndex - firstIndex + 1;
    }

    return number;
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int k, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
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

    return 0;
}

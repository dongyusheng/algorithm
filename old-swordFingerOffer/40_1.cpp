// https://blog.csdn.net/qq_41453285/article/details/108446535
#include <iostream>
#include <stdlib.h>
#include <vector>
 
using namespace std;

int RandomInRange(int n, int m);
void Swap(int *data1, int *data2);
int Partition(int *numbers, int length, int start, int end);

void getLeastNumbers(int *input, int n, int *output, int k)
{
    if(input == nullptr || n <= 0 || output == nullptr || k <= 0 || k > n)
        return;
    
    int result;
    int start = 0;
    int end = n - 1;

    int index = Partition(input, n, start, end);

    // 不等于k-1就一直判断
    while(index != (k - 1))
    {
        // 如果index在k-1的左边, 调整右区间
        if(index < (k - 1))
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
        // 如果index在k-1的右边, 调整左区间
        if(index > (k - 1))
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
    }

    // while循环结束之后index = k - 1, 并且arr[index]和index左边的元素加起来就是前k个数字
    
    // 遍历前k个元素即可
    for(int i = 0; i < k; ++i)
        output[i] = input[i]; 
}

int RandomInRange(int n, int m)
{
    int result = (random() % (m - n + 1)) + n;
    return result;
}

void Swap(int *data1, int *data2)
{
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

int Partition(int *numbers, int length, int start, int end)
{
    if(numbers == nullptr || length <= 0 || start < 0 || end > length)
        return -1;
    
    int index = RandomInRange(start, end);
    int small = start - 1;

    Swap(&numbers[index], &numbers[end]);

    for(index = start; index < end; ++index)
    {
        if(numbers[index] < numbers[end])
        {
            ++small;
            if(small != index)
                Swap(&numbers[small], &numbers[index]);
        }
    }

    small++;
    Swap(&numbers[small], &numbers[end]);
    return small;
}

// ====================测试代码====================
void Test(char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for(int i = 0; i < n; ++ i)
        vectorData.push_back(data[i]);

    if(expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; ++ i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result:\n");
    int* output = new int[k];
    getLeastNumbers(data, n, output, k);
    if(expectedResult != nullptr)
    {
        for(int i = 0; i < k; ++ i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;
}

// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
    int* expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
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

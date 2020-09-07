// https://blog.csdn.net/qq_41453285/article/details/108284738
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
 
using namespace std;
 
// 生成一个随机数
int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}
 
// 交换两个值
int Swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
 
// 最核心函数, 将start到end区间的元素切割为2部分, 并返回一个索引small,
// 其中在data[small]前面的元素都小于data[small], 在data[small]后面的元素都大于data[small]
int Partition(int data[], int length, int start, int end)
{
    if(data == nullptr || length <= 0 || start < 0 || end >= length)
        throw std::runtime_error("Invalid Parameters.");
    
    // 随机生成一个索引作为哨兵
    int index = RandomInRange(start, end);
    
    // 把data[index]这个元素放到最后, 用来作为比较标准
    Swap(&data[index], &data[end]);
 
    // 用来标识已经找到比data[end]小的索引, arr[small]及之前的所有元素都比data[end]小
    int small = start - 1;
 
    // 遍历所有的数组
    for(index = start; index < end; ++index)
    {
        // 如果遇到一个比data[index]小的
        if(data[index] < data[end])
        {
            ++small;
            if(small != index)
                Swap(&data[index], &data[small]);
        }
    }
 
    // 将small向前移动1位
    ++small;
    // 然后跟data[end]交换
    Swap(&data[small], &data[end]);
 
    return small;
}
 
void quickSort(int data[], int length, int start, int end)
{
    if(start == end)
        return;
    
    int index = Partition(data, length, start, end);
    if(index > end)
        Partition(data, length, start, index - 1);
    if(index < end)
        Partition(data, length, index + 1, end);
}

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

int MoreThanHalfNum(int *number, int length)
{
    if(number == nullptr || length <= 0)
        return 0;
    
    // 中位数索引
    int middle = length / 2;
    int start = 0;
    int end = length - 1;

    // 随机返回一个索引
    int index = Partition(number, length, start, end);
    while(index != middle)
    {
        // index小于中位数索引, 在右边找
        if(index < middle)
        {
            start = index + 1;
            index = Partition(number, length, start, end);
        }
        // index大于中位数索引, 在左边找
        else if(index > middle)
        {
            end = index - 1;
            index = Partition(number, length, start, end);
        }
    }

    // index最终会等于midlle, 返回中位数即可
    int result = number[index];

    // 为了安全起见, 检测一下result是否在数组中数量超过一半
    if(!CheckMoreThanHalf(number, length, result))
        return 0;
    
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


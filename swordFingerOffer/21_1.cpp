// https://blog.csdn.net/qq_41453285/article/details/108139482
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Dongshao
 * @Date: 2020-07-31 09:09:08
 * @LastEditors: Dongshao
 * @LastEditTime: 2020-08-21 09:14:04
 */
#include <cstdio>

/**
 * @description: 
 * @param:
        pData: 数组头指针
        length: 数组的长度
 * @return {type} 
 * @author: Dongshao
 */
void ReorderOddEvent(int *pData, int length)
{
    int i;
    int j;
    int flag; // 用来标记已经移动了多少位奇数
    int temp;
    
    // 遍历数组
    flag = 0;
    for(i = 0; i < length; ++i)
    {
        // 如果数字为奇数
        if((pData[i] & 0x1) != 0)
        {
            temp = pData[i];

            // 把所有的数字往后挪动一位
            for(j = i; j > flag; --j)
                pData[j] = pData[j - 1];

            pData[j] = temp;
            flag++;
        }
    }
}

void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("Test for solution:\n");
    PrintArray(numbers, length);
    ReorderOddEvent(numbers, length);
    PrintArray(numbers, length);
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", nullptr, 0);
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

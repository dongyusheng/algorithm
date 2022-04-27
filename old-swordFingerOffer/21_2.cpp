// https://blog.csdn.net/qq_41453285/article/details/108139482
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Dongshao
 * @Date: 2020-07-31 09:09:08
 * @LastEditors: Dongshao
 * @LastEditTime: 2020-08-21 09:33:27
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
    if(pData == nullptr || length == 0)
        return;
        
    int temp;
    int* pBgein = pData;
    int *pEnd = pData + length - 1;

    while(pBgein < pEnd)
    {
        // 从左往右找偶数
        while((pBgein < pEnd) && ((*pBgein & 0x1) != 0))
            pBgein++;
        
        //  从右往左找奇数
        while((pEnd > pBgein) && ((*pEnd & 0x1) == 0))
            pEnd--;
        
        if(pBgein < pEnd)
        {
            temp = *pBgein;
            *pBgein = *pEnd;
            *pEnd = temp;
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

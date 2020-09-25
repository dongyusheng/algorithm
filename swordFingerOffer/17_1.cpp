// https://blog.csdn.net/qq_41453285/article/details/108234415
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Dongshao
 * @Date: 2020-07-31 09:09:08
 * @LastEditors: Dongshao
 * @LastEditTime: 2020-08-26 10:11:55
 */

#include <cstdio>

void PrintToMaxOfNDigits(int n)
{
    if(n < 1)
        return;
    
    // 得到最大数
    int numbers = 1;
    while(n > 0)
    {
        numbers *= 10;
        n--;
    }
    
    // 打印
    for(int i = 1; i < numbers; ++i)
        printf("%d\t", i);
    printf("\n");
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    PrintToMaxOfNDigits(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}

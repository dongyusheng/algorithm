// https://blog.csdn.net/qq_41453285/article/details/108933547
#include <cstdio>

bool IsUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;

    return (number == 1) ? true : false;
}

int GetUglyNumber(int index)
{
    if(index <= 0)
        return 0;

    int number = 0;
    int uglyFound = 0;
    while(uglyFound < index)
    {
        ++number;

        if(IsUgly(number))
            ++uglyFound;
    }

    return number;
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber(index) == expected)
        printf("passed\n");
    else
        printf("failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}


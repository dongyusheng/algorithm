// https://blog.csdn.net/qq_41453285/article/details/108121144
#include <cstdio>

int NumberOf1(int n)
{
    int count = 0;

    while(n)
    {
        count++;
        n = (n - 1) & n;
    }

    return count;
}

void Test(int number, unsigned int expected)
{
    int actual = NumberOf1(number);
    if (actual == expected)
        printf("Test for %p passed.\n", number);
    else
        printf("Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}

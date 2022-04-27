// https://blog.csdn.net/qq_41453285/article/details/108472825
#include <cstdio>
#include <cstring>
#include <cstdlib>

int NumberOf1(unsigned int n);

int NumberOf1Between1AndN(unsigned int n)
{
    int number = 0;

    for(unsigned int i = 1; i <= n; ++i)
        number += NumberOf1(i);
    
    return number;
}

int NumberOf1(unsigned int n)
{
    int count = 0;

    while(n > 0)
    {
        if(n % 10 == 1)
            count++;
        
        n /= 10;
    }

    return count;
}

// ====================测试代码====================
void Test(const char* testName, int n, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    
    if(NumberOf1Between1AndN(n) == expected)
        printf("passed.\n");
    else
        printf("failed.\n"); 

}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int main(int argc, char* argv[])
{
    Test();

    return 0;
}

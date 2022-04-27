// https://blog.csdn.net/qq_41453285/article/details/108060505
#include <iostream>

using namespace std;

long long Fibonacci(unsigned int n)
{
    int results[2] = {0, 1};
    if(n <= 1)
        return results[n];
    
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN;

    for(int i = 2; i <= n; ++i)
    {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}

int main()
{
    std::cout << "Fibonacci 0: " << Fibonacci(0) << std::endl;
    std::cout << "Fibonacci 1: " << Fibonacci(1) << std::endl;
    std::cout << "Fibonacci 5: " << Fibonacci(5) << std::endl;
    std::cout << "Fibonacci 10: " << Fibonacci(10) << std::endl;

    return 0;
}

#include <iostream>

using namespace std;

long long Fibonacci(unsigned int n)
{
    if(n <= 0)
        return 0;
     
     if(n == 1)
        return 1;
    
     return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    std::cout << "Fibonacci 0: " << Fibonacci(0) << std::endl;
    std::cout << "Fibonacci 1: " << Fibonacci(1) << std::endl;
    std::cout << "Fibonacci 5: " << Fibonacci(5) << std::endl;
    std::cout << "Fibonacci 10: " << Fibonacci(10) << std::endl;

    return 0;
}

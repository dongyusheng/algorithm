// https://blog.csdn.net/qq_41453285/article/details/108123621
#include <iostream>

using namespace std;

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);


double Power(double base, int exponent)
{
    // 如果底数为0, 指数为负数, 直接返回0
    if(equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)exponent;
    
    // 如果指数为负数, 现将其转换为正数
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
    
    // 算出base的absExponent次方
    double result = PowerWithUnsignedExponent(base, absExponent);

    // 如果指数为负数, 那么将得到的结果进行倒数
    if(exponent < 0)
        result = 1.0 / result;
    
    return result;
}

bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    // 如果指数为0, 返回1即可
    if(exponent == 0)
        return 1;
    // 如果指数为1, 返回base本身即可
    if(exponent == 1)
        return base;

    // 递归调用
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    // 乘以上面的结果, 就可以将结果的次方翻倍, 例如2次方变为4次方, 4次方变为16次方......以此类推
    result *= result;

    // 如果exponent为奇数, 那还需要乘1次base
    if((exponent & 0x1) == 1)
        result *= base;

    // 返回结果
    return result; 
}

void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    return 0;
}

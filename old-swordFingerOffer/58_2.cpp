// https://blog.csdn.net/qq_41453285/article/details/108706190
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

void Reverse(char *pBgein, char *pEnd);

char* LeftRotateString(char* pStr, int n)
{
    // 判断参数是否为空
    if(pStr != nullptr)
    {
        int nLength = static_cast<int>(strlen(pStr));
        // 再判断一下n是否符合要求
        if(nLength > 0 && n > 0 && n < nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;

            // 反转字符串的前面n个字符
            Reverse(pFirstStart, pFirstEnd);
            // 反转字符串的后面部分
            Reverse(pSecondStart, pSecondEnd);
            // 反转整个字符串
            Reverse(pFirstStart, pSecondEnd);
        }
    }

    return pStr;
}

// 反转单个单词的顺序
void Reverse(char *pBgein, char *pEnd)
{
    if(pBgein == nullptr || pEnd == nullptr)
        return;
    
    while(pBgein < pEnd)
    {
        char temp = *pBgein;
        *pBgein = *pEnd;
        *pEnd = temp;

        pBgein++;
        pEnd--;
    }
}

// ====================测试代码====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
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

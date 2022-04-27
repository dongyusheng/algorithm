// https://blog.csdn.net/qq_41453285/article/details/108706190
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

void Reverse(char *pBgein, char *pEnd);

char* ReverseSentence(char *pData)
{
    if(pData == nullptr)
        return nullptr;
    
    // 定义pBein、pEnd, 分别指向单词的开头和末尾
    char *pBgein = pData;
    char *pEnd = pData;
    while(*pEnd != '\0')
        pEnd++;
    pEnd--;

    // 先反转整个字符串
    Reverse(pBgein, pEnd);

    // 再反转整个字符串中的每个单词
    pBgein = pEnd = pData;
    while(*pBgein != '\0')
    {
        // 如果第一个字符是空, 将pBgein和pEnd都后移
        if(*pBgein == ' ')
        {
            pBgein++;
            pEnd++;
        }
        // 如果pEnd遇到空或者遇到'\0'了, 反转这个单词
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBgein, --pEnd);
            // 更新pBgein和pEnd
            pBgein = ++pEnd;
        }
        // 将pEnd一直后移
        else
            pEnd++;
    }

    return pData;
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
void Test(const char* testName, char* input, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", nullptr, nullptr);
}

// 边界值测试，测试空字符串
void Test4()
{
    Test("Test4", "", "");
}

// 边界值测试，字符串中只有空格
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

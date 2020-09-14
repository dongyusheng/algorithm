// https://blog.csdn.net/qq_41453285/article/details/108576478
#include <cstdio>
#include <string>
#include <cstring>

char FirstNotRepeatingChar(const char *pString)
{
    if(pString == nullptr)
        return '\0';
    
    // 每个索引处对应字符的出现次数
    int *tempStr = new int[256];
    for(int i = 0; i < 256; ++i)
        tempStr[i] = 0;
    
    // 把元素和出现次数更新到tempStr中
    for(int i = 0; i < strlen(pString); ++i)
        tempStr[pString[i]]++;
    
    // 遍历数组的每个字符, 看看在tempStr中对应的次数是否为1
    for(int i = 0; i < strlen(pString); ++i)
    {
        if(tempStr[pString[i]] == 1)
            return pString[i];
    }

    return '\0';
}

// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}

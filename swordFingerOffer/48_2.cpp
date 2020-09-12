// https://blog.csdn.net/qq_41453285/article/details/108556165
#include <string>
#include <iostream>

int longestSubstringWithoutDuplication(const std::string& str)
{
    int curLength = 0;
    int maxLength = 0;

    // 用于存放26个英文字母的, 用于表示这个字符是否出现过, 初始化为-1表示没有出现过
    int* position = new int[26];
    for(int i = 0; i < 26; ++i)
        position[i] = -1;

    // 遍历字符串
    for(int i = 0; i < str.length(); ++i)
    {
        // 判断这个字符在上一次出现的位置
        int prevIndex = position[str[i] - 'a'];
        // 如果没有出现过, 或者当前不重复字符串长度大于curLength
        // 那么将curLength++
        if(prevIndex < 0 || i - prevIndex > curLength)
            ++curLength;
        // 如果遇到一个重复的字符
        else
        {
            // 判断当前长度是否大于maxLength, 如果是就替换
            if(curLength > maxLength)
                maxLength = curLength;

            // 更新当前长度
            curLength = i - prevIndex;
        }
        // 保存该字符的索引位置
        position[str[i] - 'a'] = i;
    }

    // 判断当前长度是否大于maxLength, 如果是就替换
    if(curLength > maxLength)
        maxLength = curLength;

    delete[] position;
    return maxLength;
}

// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication(input);
    if(output == expected)
        std::cout << "passed, with input: " << input << std::endl;
    else
        std::cout << "failed, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}

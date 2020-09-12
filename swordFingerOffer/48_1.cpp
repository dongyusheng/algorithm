// https://blog.csdn.net/qq_41453285/article/details/108556165
#include <string>
#include <iostream>

bool hashDuplication(const std::string& str, int position[]);

int longestSubstringWithoutDuplication(const std::string& str)
{
    int longest = 0;
    int count = 0;
    int *position = new int[26];

    for(int i = 0; i < str.size(); ++i)
    {
        for(int j = i; j < str.size(); ++j)
        {
            count = j - i + 1;

            const std::string& tempStr = str.substr(i, count);
            
            // 如果没有重复字符
            if(!hashDuplication(tempStr, position))
            {
                if(count > longest)
                    longest = count;
            }
            // 有重复字符了, 就不需要再往后遍历了
            else
                break;
        }
    }

    delete[] position;
    return longest;
}

bool hashDuplication(const std::string& str, int position[])
{
    for(int i = 0; i < 26; ++i)
        position[i] = -1;
    
    for(int i = 0; i < str.size(); ++i)
    {
        int value = str[i] - 'a';
        if(position[value] >= 0)
            return true;
        
        position[value] = value;
    }

    return false;
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

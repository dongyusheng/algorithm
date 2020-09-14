// https://blog.csdn.net/qq_41453285/article/details/108576478
#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

class CharStatistics
{
public:
    CharStatistics() : index(0)
    {
        for(int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }

    void Insert(char ch)
    {
        // 如果这个字符还没出现过, 把这个字符对应的索引更新为当前索引
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        // 如果出现过了, 那么就标记这个字符重复出现了
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++;
    }

    // 查找
    char FirstAppearingOnce()
    {
        char ch = '\0';
        // 用来于是在最前面的符合要求的字符
        int minIndex = numeric_limits<int>::max();

        // 遍历数组
        for(int i = 0; i < 256; ++i)
        {
            // 如果这个字符对应出现的次数大于0, 并且这个字符对应的索引小于minIndex
            if(occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char) i;
                minIndex = occurrence[i]; // 更新索引
            }
        }

        // 返回字符
        return ch;
    }

private:
    // occurrence[i]: A character with ASCII value i;
    // occurrence[i] = -1: The character has not found;
    // occurrence[i] = -2: The character has been found for mutlple times
    // occurrence[i] >= 0: The character has been found only once
    int occurrence[256];
    int index;
};


// ====================测试代码====================
void Test(const char* testName, CharStatistics chars, char expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}

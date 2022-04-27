// https://blog.csdn.net/qq_41453285/article/details/108125937
#include <cstdio>

bool matchCore(const char *str, const char *pattern);

bool match(const char *str, const char *pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;
    
    return matchCore(str, pattern);
}

bool matchCore(const char *str, const char *pattern)
{
    // 如果都匹配到结尾了, 直接返回true
    if(*str == '\0' && *pattern == '\0')
        return true;
    // 如果str未匹配完, 而pattern匹配完了, 返回false
    if(*str != '\0' && *pattern == '\0')
        return false;
    
    // 如果模式的下一个字符为*
    if(*(pattern + 1) == '*')
    {
        // 如果当前字符相等, 或者模式为., 则str与模式都匹配
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 2)   // 移动到下一个字符进行匹配, 同时忽略模式后面的*和模式中当前这个字符
                    || matchCore(str + 1, pattern)   // 或者保持当前的模式不变, str移动到下一个字符
                    || matchCore(str, pattern + 2);  // 不移动str, 忽略模式后面的*和模式中当前这个字符
        
        // 如果当前字符与模式不匹配, 但是由于下一个字符是*, 因此我们可以忽略模式中的*和前一个字符
        else
            return matchCore(str, pattern + 2);
    }

    // 下一个字符不是*, 那么比较简单, 直接进行比较匹配即可
    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);
    
    return false;
}

void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}

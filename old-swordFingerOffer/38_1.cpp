// https://blog.csdn.net/qq_41453285/article/details/108283837
#include <cstdio>

void Permutation(char *pStr, char *pBgein);

void Permutation(char *pStr)
{
    if(pStr == nullptr)
        return;
    
    // 第1个pStr作为字符串起始地址, 第2个pStr作为第一个操作的字符
    Permutation(pStr, pStr);
}

void Permutation(char *pStr, char *pBgein)
{
    if(*pBgein == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        // 从pBgein开始, 对每个字符进行交换
        for(char *pCh = pBgein; *pCh != '\0'; ++pCh)
        {
            // 取到该字符之后, 下面开始递归排列组合

            // pBgein是不动的, 但是pCh会向后移动

            // 将pCh所指的内容与*pBgein所指的内容进行互换
            char temp = *pCh;
            *pCh = *pBgein;
            *pBgein = temp;

            // 保持pBgein位置的元素不动, 对pBgein+1处之后的元素再进行递归
            Permutation(pStr, pBgein + 1);

            // 然后把元素交换回来, 之后把pCh向后移动开始下一轮的组合
            temp = *pCh;
            *pCh = *pBgein;
            *pBgein = temp;
        }
    }
}

// ====================测试代码====================
void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    return 0;
}

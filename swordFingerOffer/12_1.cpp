// https://blog.csdn.net/qq_41453285/article/details/108104844
#include <cstdio>
#include <string.h>


bool hasPathCore(const char *matrix, int rows, int cols, int row, int col, const char* str, int &pathLnegth, bool *visited);

/**
 * @description: 在matrix矩阵数组中查找到str字符串所在的路径
 * @param:
         matrix: 矩阵数组
         rows: 数组的行数
         clos: 数组的列数
         str: 要查找的字符串
 * @return:
         true: 在matrix中找到了str
         false: 在matrix中没有找到str
 * @author: Dongshao
 */
bool hasPath(const char *matrix, int rows, int cols, const char *str)
{
    if(matrix == nullptr || rows <=0 || cols <=0 || str == nullptr)
        return false;
    
    // 定义一个布尔数组, 用来表示是否遍历过了指定的位置, 1代表已经遍历到了这个位置, 0代表还没有遍历过这个位置
    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    // 用来存储已经匹配到str字符的路径长度
    int pathLength = 0;

    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++ col)
        {
            // 从数组中的每一个位置开始遍历查找, 是否存在str的路径
            if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
            {
                delete[] visited;
                visited = nullptr;
                return true;
            }
        }
    }

    delete[] visited;
    visited = nullptr;

    return false;
}

/**
 * @description: 在matrix中匹配字符
 * @param:
         matrix: 矩阵数组
         rows: 数组的行数
         clos: 数组的列数
         row: 当前遍历到的行数
         col: 当前遍历到的列数
         str: 字符串头指针
         pathLength: 当前遍历到字符串哪个索引处了
         visited: 布尔数组头指针
 * @return {type} 
 * @author: Dongshao
 */
bool hasPathCore(const char *matrix, int rows, int cols, int row, int col, const char* str, int &pathLength, bool *visited)
{
    // 如果匹配到字符串的末尾了, 返回true
    if(str[pathLength] == '\0')
        return true;
    
    // 是否存在路径
    bool hasPath = false;

    // 如果: 1.未越界、2.当前索引处的字符与str对应的字符相等、3.visited对应的索引处为0, 表示还没有遍历过
    // 上面的条件都满足, 则继续遍历
    if(row >=0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[pathLength]
        && !visited[row * cols + col])
    {
        // 开始匹配下一个字符, 将pathLength索引++
        ++pathLength;
        // 将当前的数组索引设置为true, 表示遍历过了这个节点
        visited[row * cols + col] = true;

        // 开始递归遍历上下左右
        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
                    || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
                    || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
                    || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
        
        // 如果上下左右都没有匹配到字符, 则回溯回去
        if(!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}

void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}

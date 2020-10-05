// https://blog.csdn.net/qq_41453285/article/details/108553911
#include <algorithm>
#include <iostream>

int getMaxValue_solution(const int *values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    
    int *maxValues = new int[cols];

    int up;
    int left;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            up = 0;
            left = 0;
            
            // 上面有元素
            if(i > 0)
                up = maxValues[j];
            // 左侧有元素
            if(j > 0)
                left = maxValues[j - 1];
            
            maxValues[j] = std::max(up, left) + values[i * cols + j];
        }
    }

    int result = maxValues[cols - 1];
    delete [] maxValues;

    return result;
}


// ====================测试代码====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{
    if(getMaxValue_solution(values, rows, cols) == expected)
        std::cout << testName << ": passed." << std::endl;
    else
        std::cout << testName << ": failed." << std::endl;
}

void test1()
{
    // 三行三列
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    test("test1", (const int*) values, 3, 3, expected);
}

void test2()
{
    //四行四列
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2", (const int*) values, 4, 4, expected);
}

void test3()
{
    // 一行四列
    int values[][4] = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3", (const int*) values, 1, 4, expected);
}

void test4()
{
    int values[4][1] = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", (const int*) values, 4, 1, expected);
}

void test5()
{
    // 一行一列
    int values[][1] = {
        { 3 }
    };
    int expected = 3;
    test("test5", (const int*) values, 1, 1, expected);
}

void test6()
{
    // 空指针
    int expected = 0;
    test("test6", nullptr, 0, 0, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}

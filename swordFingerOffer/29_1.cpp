// https://blog.csdn.net/qq_41453285/article/details/108186893
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Dongshao
 * @Date: 2020-07-31 09:09:08
 * @LastEditors: Dongshao
 * @LastEditTime: 2020-08-24 11:59:20
 */

#include <stdio.h>

void PrintMatrixCircle(int **numbers, int columns, int rows, int start);

void PrintMatrixClockwisely(int **numbers, int columns, int rows)
{
    if(numbers == nullptr || columns <=0 || rows <= 0)
        return;

    // 从最外圈开始遍历
    int start = 0;

    while((columns > start * 2) && (rows > start * 2))
    {
        // 打印这一圈的内容
        PrintMatrixCircle(numbers, columns, rows, start);

        // 将start++, 再次打印内圈的内容
        ++start;
    }
}

// 打印一圈的内容
void PrintMatrixCircle(int **numbers, int columns, int rows, int start)
{
    // 算出边界的列索引
    int endX = columns - 1 - start;
    // 算出边界的行索引
    int endY = rows - 1 - start;

    // 1.从左到右打印一行
    // 不需要任何判断条件，直接打印就可以了
    for(int i = start; i <= endX; ++i)
    {
        int number = numbers[start][i];
        printf("%d\t", number);
    }

    // 2.从上到下打印一列
    // 需要满足条件: 终止行号 > 起始行号
    if(start < endY)
    {
        for(int i = start + 1; i <= endY; ++i)
        {
            int number = numbers[i][endX];
            printf("%d\t", number);
        }
    }

    // 3.从右到左打印一行
    // 需要满足条件: 终止行号 > 起始行号, 并且终止列号 > 起始列号
    if(start < endX && start < endY)
    {
        for(int i = endX - 1; i >= start; --i)
        {
            int number = numbers[endY][i];
            printf("%d\t", number);
        }
    }

    // 4.从下岛上打印一列
    // 需要满足条件: 终止行号 > 起始行号 + 2(因为打印时用的是索引, 所以下面减1而不是减2), 并且终止列号 > 起始列号
    if(start < endX && start < endY - 1)
    {
         for(int i = endY - 1; i >= start + 1; --i)
        {
            int number = numbers[i][start];
            printf("%d\t", number);
        }
    }
}


// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}

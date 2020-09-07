// https://blog.csdn.net/qq_41453285/article/details/108446535
#include <set>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

// 集合, 使用greater规定集合中的元素从大到小进行排序
typedef multiset<int, greater<int>> intSet;
// 迭代器
typedef multiset<int, greater<int>>::iterator setIterator;

void getLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
    // 清空集合
    leastNumbers.clear();

    if(k < 1 || data.size() < k)
        return;
    
    // 数组迭代器
    vector<int>::const_iterator iter = data.cbegin();
    // 遍历整个数组
    for(; iter != data.cend(); ++iter)
    {
        // 如果容器还没满, 直接插入
        if(leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            // 因为集合是按照从大到小进行排序的, 因此begin()就是最大元素直接取出即可
            setIterator iterGreatest = leastNumbers.begin();

            // 判断当前元素是否比leastNumbers.begin()小, 如果小的话就插入
            if(*iter < *(leastNumbers.begin()))
            {
                // 先移除再插入
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}


// ====================测试代码====================
void Test(char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for(int i = 0; i < n; ++ i)
        vectorData.push_back(data[i]);

    if(expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; ++ i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    intSet leastNumbers;
    getLeastNumbers(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}

// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
    int* expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
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

    return 0;
}

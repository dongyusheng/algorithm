// https://blog.csdn.net/qq_41453285/article/details/108699935
#include <cstdio>

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
    bool found = false;
    if(data == nullptr || length <= 0 || num1 == nullptr || num2 == nullptr)
        return found;
    
    // 指向头和尾
    int ahead = 0;
    int atail = length - 1;
    int tempSum;

    while(atail > ahead)
    {
        tempSum = data[ahead] + data[atail];

        // 如果这2个数字等于sum, 退出
        if(tempSum == sum)
        {
            *num1 = data[ahead];
            *num2 = data[atail];
            found = true;
            return found;
        }
        // 如果tempSum > sum, 将tail向前面移动
        else if(tempSum > sum)
            atail--;
        // 如果tempSum < sum, 将ahead向后面移动
        else
            ahead++;
    }

    return found;
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int sum, bool expectedReturn)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    
    int num1, num2;
    int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
    if(result == expectedReturn)
    {
        if(result)
        {
            if(num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("FAILED. \n");
        }
        else
            printf("Passed. \n");
    }
    else
        printf("FAILED. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

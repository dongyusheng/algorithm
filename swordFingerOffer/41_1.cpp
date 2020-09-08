// https://blog.csdn.net/qq_41453285/article/details/108455161
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;

template<typename T> class DynamicArray
{
public:
    void Insert(T num)
    {
        // 如果两个堆(元素总数)为空, 或者数量总数为偶数, 就把新元素插入到右侧的最小堆中
        if(((min.size() + max.size()) & 1) == 0)
        {
            // 最大堆不为空, 并且num小于左侧最大堆的最大值时, 就把自己插入到最大堆中, 然后把最大堆中的原最大元素拿出来加入到最小堆中
            // 如果num比最大堆的最大值还大, 就不执行if, 直接把num插入到最小堆中即可
            if(max.size() > 0 && num < max[0])
            {
                // 把这个元素插入到max中
                max.push_back(num);
                // push_heap()函数用来调整堆, 因为上面插入了1个新的元素, 因此要调用该函数来调整堆
                push_heap(max.begin(), max.end(), less<T>());

                // 取得左侧最大堆的最大值
                num = max[0];

                // 把最大堆中的最大值移到vector的尾部(非删除)
                pop_heap(max.begin(), max.end(), less<T>());
                // 此时才真正删除最大值
                max.pop_back();
            }

            // 把num加到最小堆中
            min.push_back(num);
            // 重新调整最小堆
            push_heap(min.begin(), min.end(), greater<T>());
        }
        // 如果两个堆(元素总数)为奇数, 那么把新元素插入到左侧的最大堆中
        else
        {
            // 最小堆不为空, 并且num大于右侧最小堆的最小值时, 就把自己插入到最小堆中, 然后把最小堆中的原最小元素拿出来加入到最大堆中
            // 如果num比最小堆的最小值还小, 就不执行if, 直接把num插入到最大堆中即可
            if(min.size() > 0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }

    T GetMedian()
    {
        int size = min.size() + max.size();
        if(size == 0)
            throw std::runtime_error("No numbers are available");

        T median = 0;

        // 如果元素数量为奇数, 直接返回最小堆中的最小值即可
        if((size & 1) == 1)
            median = min[0];
        // 如果元素数量为偶数, 返回最"大堆中的最大值"和"最小堆中的最小值"的一半
        else
            median = (min[0] + max[0]) / 2;

        return median;
    }

private:
    // max(最大堆)中的元素都小于min(最小堆)中的元素

    vector<T> min;
    vector<T> max;

    // min.push_heap(xx, xx, greater<T>()) 表示构造最小堆, 所有元素从大到小排序
    // max.push_heap(xx, xx, less<T>())    表示构造最大堆, 所有元素从小到大排序
};


// ====================测试代码====================
void Test(char* testName, DynamicArray<double>& numbers, double expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try
    {
        numbers.GetMedian();
        printf("FAILED.\n");
    }
    catch(const exception&)
    {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}

// https://blog.csdn.net/qq_41453285/article/details/108259425
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity) : _capacity(capacity) { }

    // 从缓存中取元素
    int get(int key);

    // 向缓存中添加一个元素
    void put(int key, int value);
private:
    // 插入一个新元素
    void Insert(int key, int value)
    {
        // 从链表头部插入
        _list.push_front(key);

        // 然后插入到map中, 注意迭代器指向的是链表的头部(最新访问元素)
        _map[key] = std::make_pair(value, _list.begin());
    }
private:
    int _capacity;         // 当前缓存的容量
    std::list<int> _list; // 存储元素, 链表头存储最新访问的元素, 链表尾存储旧访问元素
    /*
        key:   对应的与list内的元素一样
        value: 为一个pair结构, 其中pair->first对应的是value, pair->second对应的是链表的迭代器位置
    */
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> _map;
};

/*
    从缓存中取元素, 分为2种情况:
        1. 元素不存在, 直接返回-1
        2. 元素存在, 那么把这个元素从链表尾部移除, 然后再重新添加即可
*/
int LRUCache::get(int key)
{
    // 从unordered_map中查找这个元素是否存在, 复杂度为O(1)
    auto iter = _map.find(key);

    // 1. 如果不存在, 那直接返回-1
    if(iter == _map.end())
        return -1;

    // 2.如果存在, 那么把这个元素从链表移除, 然后再重新添加进链表即可

    // 先把value保存下来, 因为下面链表调用erase()之后iter就失效了
    int value = iter->second.first;

    // 把这个元素从链表移除, 然后重新添加到链表头部
    _list.erase(iter->second.second); // iter->second得到map的value(pair结构), 然后iter->second.second得到链表的迭代器进行删除
    
    // 然后再调用Insert()重新插入即可
    Insert(key, value);

    return value;
}

/*
    向缓存中添加一个元素, 分为3种情况:
        1. 元素已存在, 直接更新即可
        2. 元素不存在, 且缓存未满, 直接调用Insert插入即可
        3. 元素不存在, 且缓存已满, 移除最后一个元素再添加
*/
void LRUCache::put(int key, int value)
{
    // 1. 元素已存在, 直接更新即可

    // 此处由于调用了get(), 所以这个key会被移动到链表的头部, 不需要再手动完成了
    if(get(key) != -1)
    {
        // 更新至即可
        _map[key].first = value;
        return;
    }

    // 2.元素不存在, 且缓存未满, 直接调用Insert插入即可
    if(_map.size() < _capacity)
    {
        Insert(key, value);
    }
    // 3. 元素不存在, 且缓存已满, 移除最后一个元素再添加
    else
    {
        // 获取最后一个元素的值, 并移除最后一个节点
        int eraseValue = _list.back();
        _list.pop_back();

        // 将这个值也从unordered_map中删除
        _map.erase(eraseValue);

        // 然后插入新元素即可
        Insert(key, value);
    }
}

int main()
{
    LRUCache cache(2);     // 缓存容量2

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // 返回  1
    cache.put(3, 3);                        // 该操作会使得关键字 2 作废
    std::cout << cache.get(2) << std::endl; // 返回 -1 (未找到)
    cache.put(4, 4);                        // 该操作会使得关键字 1 作废
    std::cout << cache.get(1) << std::endl; // 返回 -1 (未找到)  
    std::cout << cache.get(3) << std::endl; // 返回  3   
    std::cout << cache.get(4) << std::endl; // 返回  4   

    return 0;
}

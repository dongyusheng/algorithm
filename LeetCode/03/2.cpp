class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        
        unordered_set<char> mySet; // 存储最长子串
        int rk = -1;               // 右指针, 先初始化为-1
        int maxSize = 0;           // 当前最长子串的长度
        int length = s.size();     // s字符串的长度

        // 左指针就是i
        for(int i =0; i < length; ++i)
        {
            // 每次进入循环就把左指针向右移动1位, 并把之前的字符移除, 开始处理下一个子串
            // 但是由于第一次进入for循环i=0不需要移位, 此处需要一个if判断
            if(i != 0)
                mySet.erase(s[i - 1]);
            
            // 逐渐遍历右指针
            // 如果右指针指向的下一个元素不在当前的子串中, 那么就加入到mySet中
            while(rk + 1 < length && !mySet.count(s[rk + 1]))
            {
                mySet.insert(s[rk + 1]);
                // 然后右指针向后偏移继续查找
                rk++;
            }

            // 如果查找到了遇到了重复字符, 进行判断当前子串是否大于maxSize
            maxSize = (rk - i + 1> maxSize) ? rk - i + 1: maxSize;
        }

        return maxSize;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length == 0)
            return 0;

        unordered_set<char> mySet;
        int maxSize = 0;

        // 从第1个字符开始判断
        for(int i = 0; i < length; ++i)
        {
            // 每次开始判断要把unordered_set清空
            mySet.clear();

            // 从i开始向后查找最长的无重复字符的字符串
            for(int j = i; j < length; ++j)
            {
                // 如果这个字符在前面没出现过, 就加入到unordered_set中
                if(mySet.find(s[j]) == mySet.end())
                    mySet.insert(s[j]);
                else
                    break;
            }

            // 如果这次查找到的字符串比之前的长, 那么就改变maxSize
            if(mySet.size() > maxSize)
                maxSize = mySet.size();
        }

        return maxSize;
    }
};

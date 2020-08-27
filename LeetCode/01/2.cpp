// https://blog.csdn.net/qq_41453285/article/details/108265752
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;

        // 把所有的元素都添加进哈希中, key为值, value为索引
        unordered_map<int, int> _map;
        for(int i = 0; i < (int)nums.size(); ++i)
            _map.insert({nums[i], i});
        
        // 遍历所有元素
        for(int i = 0; i < (int)nums.size(); ++i)
        {
            // 还需要的差值
            int needNum = target - nums[i];

            // 如果找到了差值, 那么就返回. 因为题目不允许数组中同一个元素不能使用两遍, 所以有&&后面的1次判断
            if((_map.find(needNum) != _map.end()) && (_map[needNum] != i))
            {
                vec.push_back(i);
                vec.push_back(_map[needNum]);
                break;
            }
        }

        return vec;
    }
};

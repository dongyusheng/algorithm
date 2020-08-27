// https://blog.csdn.net/qq_41453285/article/details/108265752
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;

        //key为值, value为索引
        unordered_map<int, int> _map;

        // 遍历所有元素
        for(int i = 0; i < (int)nums.size(); ++i)
        {
            // 还需要的差值
            int needNum = target - nums[i];

            // 如果这个元素在unordered_map中, 然后break
            if(_map.find(needNum) != _map.end())
            {
                vec.push_back(i);
                vec.push_back(_map[needNum]);
                break;
            }

            // 把这个元素添加到unordered_map中, 供后面使用
            _map.insert({nums[i], i});
        }

        return vec;
    }
};

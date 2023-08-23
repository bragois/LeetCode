class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // key - array element, value - index
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            // check if element has a complement in the current map
            if(map.count(target - nums[i]))
            {
                return vector<int> {map[target - nums[i]], i};
            }
            map.insert ({nums[i], i});
        }
        return vector<int> {0, 0};
    }
};
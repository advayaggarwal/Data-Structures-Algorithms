class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m; //{element,index}
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            auto it = m.find(target - nums[i]);

            if (it != m.end() && it->second != i)
            {
                res.push_back(it->second);
                res.push_back(i);
                return res;
            }

            m[nums[i]] = i;
        }
        return res;
    }
};
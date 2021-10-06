class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int, int>, int>dp;
        return helper(nums, target, 0, 0, dp);
    }

    int helper(vector<int>&nums, int &target, int sum, int index,  map<pair<int, int>, int>&dp)
    {
        if (index == nums.size())
        {
            return sum == target ? 1 : 0;
        }
        if (dp.find({index, sum}) != dp.end())  return dp[ {index, sum}];

        return dp[ {index, sum}] = helper(nums, target, sum + nums[index], index + 1, dp) + helper(nums, target, sum - nums[index], index + 1, dp);
    }
};
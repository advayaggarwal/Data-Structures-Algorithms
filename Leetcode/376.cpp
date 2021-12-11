//Recursion
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        return max(helper(0, nums, 1), helper(0, nums, 0)); //wiggle seq can start from positive & negative as well
    }

    int helper(int i, vector<int>& nums, int pos)
    {
        if (i >= nums.size())    return 0;

        if (pos)
        {
            if (i == nums.size() - 1 or nums[i + 1] - nums[i] > 0)
            {
                return 1 + helper(i + 1, nums, 0);
            }

            else return helper(i + 1, nums, 1);
        }

        else
        {
            if (i == nums.size() - 1 or nums[i + 1] - nums[i] < 0)
            {
                return 1 + helper(i + 1, nums, 1);
            }

            else return helper(i + 1, nums, 0);
        }
    }
};

//DP
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2)    return nums.size();

        int pos = 1, neg = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1]) pos = neg + 1;
            else if (nums[i] < nums[i - 1])    neg = pos + 1;
        }

        return max(pos, neg);
    }
};
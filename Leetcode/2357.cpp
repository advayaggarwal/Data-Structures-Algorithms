//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int count = 0;

        while (nonZero(nums))
        {
            count++;
            int mini = INT_MAX;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i]) mini = min(mini, nums[i]);
            }

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i]) nums[i] -= mini;
            }
        }

        return count;
    }

    bool nonZero(vector<int>&nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)    return true;
        }

        return false;
    }
};

//Using unordered set
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_set<int>s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)   s.insert(nums[i]);
        }

        return s.size();
    }
};
//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();

        if (n < 3)   return 0;

        int count = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int diff = nums[i + 1] - nums[i];
            for (int j = i + 2; j < n; j++)
            {
                if (nums[j] - nums[j - 1] == diff)    count++;
                else break;
            }
        }

        return count;
    }
};

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();

        if (n < 3)   return 0;

        int count = 0;

        vector<int>dp(n, 0); //dp[i] represents no of arithmetic slices ending at i

        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])    dp[i] = 1 + dp[i - 1];

            count += dp[i];
        }

        return count;
    }
};

//We can remove the dp array as we only need 1 previous value
//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();

        if (n < 3)   return 0;

        int count = 0;

        int prevCount = 0;

        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])    prevCount += 1;
            else prevCount = 0;

            count += prevCount;
        }

        return count;
    }
};
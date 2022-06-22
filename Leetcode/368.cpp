//LIS Pattern
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = nums.size(), lastIndex, ans = 0;
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1), hash(n);
        vector<int>res;

        for (int i = 1; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (ans < dp[i])
            {
                ans = dp[i];
                lastIndex = i;
            }
        }

        while (lastIndex != hash[lastIndex])
        {
            res.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }

        res.push_back(nums[lastIndex]);

        return res;
    }
};
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();

        vector<pair<int, int>>dp(n, {1, 1}); //{length, count}, dp[i]: {length, number of LIS which ends with nums[i]}

        int lis = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j].first + 1 > dp[i].first)
                    {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }

                    else if (dp[j].first + 1 == dp[i].first)
                    {
                        dp[i].second += dp[j].second;
                    }
                }
            }

            if (lis == dp[i].first)  count += dp[i].second;

            else if (lis < dp[i].first)
            {
                lis = dp[i].first;
                count = dp[i].second;
            }
        }

        return count;
    }
};
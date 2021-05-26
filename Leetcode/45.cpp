class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= n - 1)   dp[i] = 1;

            else
            {
                int minj = INT_MAX;
                bool flag = false;
                for (int j = i + 1; j <= (i + nums[i]); j++)
                {
                    flag = true;
                    if (dp[j] == 1)
                    {
                        dp[i] = 2;
                        break;
                    }
                    minj = min(minj, dp[j]);
                }

                if (dp[i] == -1)
                {
                    if (!flag || minj == INT_MAX ) dp[i] = INT_MAX;
                    else dp[i] =  1 + minj;
                }
            }
        }

        return dp[0];
    }
};
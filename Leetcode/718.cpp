//Time complexity - O(n*m*min(n,m))
//Space complexity - O(n*m*1000)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        vector<vector<vector<int>>>dp(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(1001, -1)));
        return helper(0, nums1, 0, nums2, dp, 0);
    }

    int helper(int i, vector<int>&nums1, int j, vector<int>&nums2, vector<vector<vector<int>>>&dp, int count)
    {
        if (i == nums1.size() or j == nums2.size())  return count;
        if (dp[i][j][count] != -1)  return dp[i][j][count];

        int same = count;

        if (nums1[i] == nums2[j])    same = helper(i + 1, nums1, j + 1, nums2, dp, count + 1);
        return dp[i][j][count] = max({same, helper(i + 1, nums1, j, nums2, dp, 0), helper(i, nums1, j + 1, nums2, dp, 0)});
    }
};


//Time complexity - O(n*m)
//Space complexity - O(n*m)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }

            }
        }

        return ans;
    }
};

//Time complexity - O(n*m)
//Space complexity - O(1)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size(), maxCount = 0;

        for (int i = -n + 1; i < m; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i + j < 0) continue;
                else if (i + j >= m)   break;
                else if (nums1[i + j] == nums2[j])
                {
                    count++;
                    maxCount = max(maxCount, count);
                }
                else    count = 0;
            }
        }

        return maxCount;
    }
};
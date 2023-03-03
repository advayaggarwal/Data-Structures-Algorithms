//Time complexity - O(n*n*m)
//Space complexity - O(m)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                unordered_map<int, int>mp;
                mp[0] = 1;
                int sum = 0;
                for (int k = 0; k < m; k++)
                {
                    sum += matrix[k][j];
                    if (i > 0)   sum -= matrix[k][i - 1];

                    if (mp.count(sum - target)) count += mp[sum - target];
                    mp[sum]++;
                }
            }
        }

        return count;
    }
};

//Extension to Leetcode 560 - Subarray sum equals K
//Prefix sum on columns
//Time complexity - O(m*m*n)
//Space complexity - O(n)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;

        for (int i = 0; i < m; i++)
        {
            vector<int>nums(n);
            for (int j = i; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    nums[k] += matrix[j][k];
                }
                ans += subarrySumEqualsK(nums, target);
            }
        }

        return ans;
    }

    int subarrySumEqualsK(vector<int>&nums, int target)
    {
        unordered_map<int, int>m;
        m[0] = 1;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (m.count(sum - target)) ans += m[sum - target];
            m[sum]++;
        }

        return ans;
    }
};
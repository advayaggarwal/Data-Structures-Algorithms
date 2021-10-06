//Bottom Up DP
//Time complexity - O(n^2)
#define vi vector<int>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lisBU(nums, n);
    }

    int lisBU(vi &v, int n)
    {
        vi dp(n, 1); //dp[i] denotes the length of LIS ending at index i

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[j] < v[i])    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};


//Time complexity - O(n*logn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int>sub;

        for (int num : nums)
        {
            if (sub.size() == 0 or sub[sub.size() - 1] < num)
            {
                sub.push_back(num);
            }

            else
            {
                int index = lower_bound(sub.begin(), sub.end(), num) - sub.begin();
                sub[index] = num;
            }
        }

        return sub.size();
    }
};
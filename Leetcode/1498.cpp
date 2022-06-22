//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target)
    {
        return (helper(0, nums, target, -1, -1)) % mod;
    }

    int helper(int i, vector<int>&nums, int target, int mini, int maxi)
    {
        if (i == nums.size())
        {
            if (mini != -1 && maxi != -1) //should be non-empty
            {
                int sum = nums[mini] + nums[maxi];
                if (sum <= target)   return 1;
            }

            return 0;
        }

        int take = 0;

        if (mini == -1 or maxi == -1)    take = helper(i + 1, nums, target, i, i);
        else
        {
            int nmini = mini, nmaxi = maxi;
            if (nums[i] < nums[mini]) nmini = i;
            if (nums[i] > nums[maxi])    nmaxi = i;
            take = helper(i + 1, nums, target, nmini, nmaxi);
        }

        int notTake = helper(i + 1, nums, target, mini, maxi);

        return (take + notTake) % mod;
    }
};

//Top Down DP
//Time complexity - O(n^3)
//Space complexity - O(n^3)
class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return (helper(0, nums, target, -1, -1, dp)) % mod;
    }

    int helper(int i, vector<int>&nums, int target, int mini, int maxi, vector<vector<vector<int>>>&dp)
    {
        if (i == nums.size())
        {
            if (mini != -1 && maxi != -1)
            {
                int sum = nums[mini] + nums[maxi];
                if (sum <= target)   return 1;
            }

            return 0;
        }

        if (mini != -1 && maxi != -1 && dp[i][mini][maxi] != -1) return dp[i][mini][maxi];

        int take = 0;

        if (mini == -1 or maxi == -1)    take = helper(i + 1, nums, target, i, i, dp);
        else
        {
            int nmini = mini, nmaxi = maxi;
            if (nums[i] < nums[mini]) nmini = i;
            if (nums[i] > nums[maxi])    nmaxi = i;
            take = helper(i + 1, nums, target, nmini, nmaxi, dp);
        }

        int notTake = helper(i + 1, nums, target, mini, maxi, dp);

        int ans = (take + notTake) % mod;
        if (mini != -1 && maxi != -1)    dp[i][mini][maxi] = ans;
        return ans;
    }
};

//Two Sum Approach and Precomputing the powers of 2
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>pows(n, 1);

        for (int i = 1; i < n; i++)  pows[i] = pows[i - 1] * 2 % mod;

        int low = 0, hi = n - 1, ans = 0;

        while (low <= hi)
        {
            if (nums[low] + nums[hi] <= target)
            {
                ans += pows[hi - low];
                ans %= mod;
                low++;
            }

            else hi--;
        }

        return ans;
    }
};

//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    const int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end()); //min and max element won't change that's why we can sort
        int n = nums.size();
        int start = 0, end = n - 1;
        int ans = 0;
        while (start <= end)
        {
            if (nums[start] + nums[end] <= target)
            {
                ans += pow(2, end - start);
                ans %= mod;
                start++;
            }
            else end--;
        }

        return ans;
    }

    long long int pow(long long int a, long long int b)
    {
        long long int res = 1;

        while (b)
        {
            if (b & 1)   res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }

        return res;
    }
};


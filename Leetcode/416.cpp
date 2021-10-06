//Top Down DP
#define vi vector<int>
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums)    sum += num;

        if (sum % 2 != 0)   return false; //if sum is odd we can't divide it into 2 equal parts

        vector<vi>dp(n + 1, vi(sum / 2 + 1, -1));
        //if we get one partition of sum/2 then definitely other partition will also be sum/2
        return  equalSumPartition(nums, sum / 2, 0, dp);
    }

    bool equalSumPartition(vi &arr, int target, int index, vector<vi>&dp)
    {
        if (index == arr.size())    return false;

        if (target == 0)    return true;

        if (dp[index][target] != -1)  return dp[index][target];

        bool inc = false, exc = false;

        if (target >= arr[index]) inc = equalSumPartition(arr, target - arr[index], index + 1, dp);
        exc = equalSumPartition(arr, target, index + 1, dp);

        return dp[index][target] = (inc || exc);
    }
};

//Bottom Up DP
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums)    sum += num;

        if ((sum % 2) != 0) return false; //if sum is odd we can't divide it into 2 equal parts

        //if we get one partition of sum/2 then definitely other partition will also be sum/2
        return  equalSumPartitionBU(nums, sum / 2);
    }

    bool equalSumPartitionBU(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++)    dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int sum = 1; sum <= target; sum++)
            {
                if (sum >= nums[i - 1])
                {
                    dp[i][sum] = dp[i - 1][sum - nums[i - 1]] || dp[i - 1][sum];
                }

                else
                {
                    dp[i][sum] = dp[i - 1][sum];
                }
            }
        }

        return dp[n][target];
    }

};
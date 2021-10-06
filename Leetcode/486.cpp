//Recursion
//Time complexity - O(2^n)
class Solution {
public:

    int helper(vector<int>&nums, int i, int j)
    {
        if (i > j)   return 0;

        if (i == j)    return nums[i];

        int l = nums[i] + min(helper(nums, i + 2, j), helper(nums, i + 1, j - 1));

        int r = nums[j] + min(helper(nums, i, j - 2), helper(nums, i + 1, j - 1));

        return max(l, r);
    }

    bool PredictTheWinner(vector<int>& nums) {

        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) sum += nums[i];

        int player1 = helper(nums, 0, n - 1);

        int player2 = sum - player1;

        return player1 >= player2 ? true : false;
    }
};
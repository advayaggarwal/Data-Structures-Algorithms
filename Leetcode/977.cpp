//Time complexity - O(n)
//Space complexity - O(n), considering answer vector

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int>ans(n);

        int i = 0, j = n - 1;
        for (int k = n - 1; k >= 0; k--)
        {
            if (abs(nums[i]) > abs(nums[j])) //largest square will be of smallest negative or largest positive
            {
                ans[k] = nums[i] * nums[i];
                i++;
            }
            else
            {
                ans[k] = nums[j] * nums[j];
                j--;
            }
        }

        return ans;
    }
};
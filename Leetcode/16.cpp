//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), closest = 0, minDiff = INT_MAX;

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)   return sum;

                if (sum < target)    j++;
                else k--;

                int diff = abs(sum - target);
                if (diff < minDiff)
                {
                    minDiff = diff;
                    closest = sum;
                }
            }
        }

        return closest;
    }
};
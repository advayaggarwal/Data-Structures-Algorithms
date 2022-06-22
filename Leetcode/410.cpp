//Binary search on answer(Sum)
//Time complexity - O(n*log(s)), where s is sum of array
//Space complexity - O(1)
class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        int mx = INT_MIN, sum = 0;

        for (int &num : nums)
        {
            mx = max(mx, num);
            sum += num;
        }

        int lo = mx, hi = sum;
        int ans = 0;
        while (lo <= hi)
        {
            int maxSumAllowed = lo + (hi - lo) / 2;

            if (minimumSubarraysRequired(maxSumAllowed, nums) <= m)
            {
                ans = maxSumAllowed;
                hi = maxSumAllowed - 1;
            }

            else    lo = maxSumAllowed + 1;
        }

        return ans;
    }

    int minimumSubarraysRequired(int maxSumAllowed, vector<int>&nums)
    {
        int currentSum = 0, splitsRequired = 0;

        for (int &num : nums)
        {
            if (currentSum + num <= maxSumAllowed)   currentSum += num;
            else
            {
                currentSum = num;
                splitsRequired += 1;
            }
        }

        return splitsRequired + 1;
    }
};
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)    return 0;
        int smallest = INT_MAX, largest = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (outOfOrder(i, n, nums))
            {
                smallest = min(smallest, nums[i]);
                largest = max(largest, nums[i]);
            }
        }

        if (smallest == INT_MAX) return 0;

        int i = 0;
        while (i < n && nums[i] <= smallest) i++;
        int j = n - 1;
        while (j >= 0 && nums[j] >= largest) j--;

        return j - i + 1;
    }

    bool outOfOrder(int i, int n, vector<int>&nums)
    {
        if (i == 0)  return nums[i] > nums[i + 1];
        if (i == n - 1)    return nums[i] < nums[i - 1];

        return (nums[i] > nums[i + 1]) or (nums[i] < nums[i - 1]);
    }
};
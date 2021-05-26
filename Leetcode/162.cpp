class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == n - 1 || nums[mid] >= nums[mid + 1]))  return mid;
            else if (mid > 0 && nums[mid] <= nums[mid - 1])    high = mid - 1;
            else low  = mid + 1;
        }
        return 0;
    }
};
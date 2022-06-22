//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)    return;
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1)   mid++;
            else
            {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
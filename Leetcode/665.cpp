//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums)
    {
        int n = nums.size();
        bool changed = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1]) //if nums[i] is out of order
            {
                if (changed)  return false; //already made 1 change and still it's not non decreasing
                //we will prefer to change nums[i]'s value, since a larger nums[i] will give you more risks that you get inversion errors after position i
                if (i == 0 or nums[i + 1] >= nums[i - 1])  nums[i] = nums[i + 1]; //we can decrease the left value
                else nums[i + 1] = nums[i]; //have to modify nums[i+1]
                changed = true;
            }
        }

        return true;
    }
};
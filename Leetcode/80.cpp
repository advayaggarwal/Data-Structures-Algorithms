//2 pointer
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 2, n = nums.size();
        if (n <= 2)    return n;

        for (int j = 2; j < n; j++)
        {

            if (nums[j] != nums[i - 2])
            {
                nums[i++] = nums[j];
            }
        }

        return i;
    }
};
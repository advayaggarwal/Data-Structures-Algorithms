//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums)
    {
        int count = 0, n = nums.size();

        for (int i = 1; i < n && count < 2; i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                count++;
                if (i > 1 && nums[i - 2] >= nums[i])
                {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return count < 2;
    }
};


//Without changing the original array
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums)
    {
        int cnt = 0;
        int mx = nums[0];
        for (int i = 1; i < nums.size() && cnt < 2; ++i) {
            if (mx >= nums[i]) {
                ++cnt;
                if (i > 1 && nums[i - 2] >= nums[i]) {
                    mx = nums[i - 1];
                    continue;
                }
            }
            mx = nums[i];
        }
        return cnt < 2;
    }
};
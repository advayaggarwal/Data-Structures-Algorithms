class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)    return 0;

        int start, end;
        int max = INT_MIN, min = INT_MAX;
        for ( start = 1; start < n; start++)
        {
            if (nums[start] < nums[start - 1]) {
                min = std::min(min, nums[start]);
            }
        }


        for ( end = n - 2; end >= 0; end--)
        {
            if (nums[end] > nums[end + 1])
            {
                max = std::max(max, nums[end]);
            }
        }


        for (int i = 0; i < n; i++)
        {
            if (nums[i] > min)
            {
                start = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < max)
            {
                end = i;
                break;
            }
        }

        return end - start >= 0 ? (end - start + 1) : 0;
    }
};
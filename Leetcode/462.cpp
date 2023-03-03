//Make all values equal to the median
//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, val = nums[n / 2];
        for (int i = 0; i < n; i++)  ans += abs(nums[i] - val);
        return ans;
    }
};

//Since we need only median value, no need to sort, use Quickselect to get the (n/2)th element
class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int ans = 0, val = nums[n / 2];
        for (int i = 0; i < n; i++)  ans += abs(nums[i] - val);
        return ans;
    }
};
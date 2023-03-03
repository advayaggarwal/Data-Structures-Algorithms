//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            if ((nums[low] + nums[high]) == 0)  return  nums[high];
            else if ((nums[low] + nums[high]) < 0)  low++;
            else high--;
        }

        return -1;
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)  return -1;

        unordered_set<int>s(nums.begin(), nums.end());
        int ans = -1;

        for (auto e : s)
        {
            if (s.count(-e))
            {
                ans = max(ans, abs(e));
            }
        }

        return ans;
    }
};
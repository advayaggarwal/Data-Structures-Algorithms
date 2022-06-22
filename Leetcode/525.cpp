//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int>m;
        int sum = 0, ans = 0;
        m[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += (nums[i] == 1 ? 1 : -1);
            if (m.count(sum) > 0)
            {
                ans = max(ans, i - m[sum]);
            }

            else m[sum] = i;
        }

        return ans;
    }
};
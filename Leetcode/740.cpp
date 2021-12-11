//Transforming this question into house robber(Max sum non adjacent elements)
//Time complexity - O(n+mx)
//Space complexity - O(mx)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int n = nums.size();
        int mx = INT_MIN;

        for (int i = 0; i < n; i++)  mx = max(mx, nums[i]);
        vector<int>v(mx + 1);

        for (int i = 0; i < n; i++)  v[nums[i]]++;

        int prev = v[0];
        int curr = max(v[0], v[1]);

        for (int i = 2; i <= mx; i++)
        {
            int temp = max(curr, i * v[i] + prev);
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};
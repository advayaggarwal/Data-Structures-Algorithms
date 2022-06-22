//Time complexity - O(m+n)
//Space complexity - O(n)
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations)
    {
        unordered_map<int, int>mp;
        int n = nums.size(), m = operations.size();
        for (int i = 0; i < n; i++)  mp[nums[i]] = i;

        for (int i = 0; i < m; i++)
        {
            int index = mp[operations[i][0]];
            nums[index] = operations[i][1];
            mp.erase(operations[i][0]);
            mp[operations[i][1]] = index;
        }

        return nums;
    }
};
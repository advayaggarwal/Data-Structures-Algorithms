//Time complexity - O(n+q)
//Space complexity - O(1)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int sum = 0;
        vector<int>res;
        for (int num : nums)
        {
            if (num % 2 == 0)    sum += num;
        }

        for (auto q : queries)
        {
            int val = q[0], index = q[1];
            if (nums[index] % 2 == 0)    sum -= nums[index];
            nums[index] += val;
            if (nums[index] % 2 == 0)    sum += nums[index];
            res.push_back(sum);
        }

        return res;
    }
};
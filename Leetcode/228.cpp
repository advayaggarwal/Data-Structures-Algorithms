//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = nums.size();
        vector<string>res;
        if (n < 1)   return res;
        int i = 0, j;

        for (j = 1; j < n; j++)
        {
            if (nums[j] != nums[j - 1] + 1)
            {
                string ans = to_string(nums[i]);
                if (i != j - 1)  ans += "->" + to_string(nums[j - 1]);
                res.push_back(ans);
                i = j;
            }
        }

        string ans = to_string(nums[i]);
        if (i != j - 1) ans += "->" + to_string(nums[j - 1]);
        res.push_back(ans);

        return res;
    }
};
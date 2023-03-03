//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums)
    {
        unordered_set<int>s(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int r = 0, no = nums[i];
            while (no)
            {
                r = r * 10 + no % 10;
                no /= 10;
            }

            s.insert(r);
        }

        return s.size();
    }
};
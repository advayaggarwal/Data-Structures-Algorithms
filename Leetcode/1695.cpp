//Sliding Window
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int n = nums.size(), i = 0, j = 0;
        int ans = 0, sum = 0;
        unordered_map<int, int>m;
        while (j < n)
        {
            m[nums[j]]++;
            sum += nums[j];

            while (i <= j && m[nums[j]] > 1) //it means it contains repeated elements
            {
                m[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            ans = max(ans, sum);
            j++;
        }

        return ans;
    }
};
//DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        int n = nums.size();
        vector<long long int>countEndingAt(n);

        long long ans = 0;
        if (nums[0] == 0)
        {
            countEndingAt[0] = 1;
            ans = 1;
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == 0)
            {
                countEndingAt[i] = 1 + countEndingAt[i - 1];
                ans += countEndingAt[i];
            }
        }

        return ans;
    }
};

//DP with space optimisation
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        int n = nums.size();
        long long ans = 0, prev = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                prev += 1;
                ans += prev;
            }

            else prev = 0;
        }

        return ans;
    }
};
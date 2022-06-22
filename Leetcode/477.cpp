//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int val = nums[i] ^ nums[j];
                ans += __builtin_popcount(val);
            }
        }

        return ans;
    }
};

//Time complexity - O(30*n)
//Space complexity - O(1)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i <= 30; i++)
        {
            int val = 1 << i;
            int zeroes = 0, ones = 0;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] & val)   ones++;
                else zeroes++;
            }

            ans += ones * zeroes;
        }

        return ans;
    }
};
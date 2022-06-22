//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k)
    {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum * (j - i + 1) < k) ans++;
            }
        }

        return ans;
    }
};

//Sliding Window
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k)
    {
        long long ans = 0, sum = 0;
        int n = nums.size();
        int i = 0, j = 0;

        while (j < n)
        {
            sum += nums[j];

            while (sum * (j - i + 1) >= k)
            {
                sum -= nums[i];
                i++;
            }

            ans += j - i + 1; //adding all subarrays ending at index j
            j++;
        }

        return ans;
    }
};
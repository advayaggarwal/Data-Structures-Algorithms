//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)    count++;
            }
        }

        return count;
    }
};

//Hashmap
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int>m;
        m[0] = 1;
        int count = 0, sum = 0;
        for (int num : nums)
        {
            sum += num;
            if (m.count(sum - k))  count += m[sum - k];
            m[sum]++;
        }

        return count;
    }
};
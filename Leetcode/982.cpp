//Time complexity - O(n^3)
//Space complexity - O(1)
class Solution {
public:
    int countTriplets(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if ((nums[i] & nums[j] & nums[k]) == 0)  count++;
                }
            }
        }

        return count;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int countTriplets(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int>m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = nums[i] & nums[j];
                m[val]++;
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (auto p : m)
            {
                if ((p.first & nums[i]) == 0)  count += p.second;
            }
        }

        return count;
    }
};
//Min and Max won't get changed in subsequence even after sorting
//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();

        for (int i = 0; i < n;)
        {
            int key = nums[i] + k;
            count++;
            int index = upper_bound(nums.begin(), nums.end(), key) - nums.begin();
            index--;
            if (index >= 0)  i = index + 1;
        }

        return count;
    }
};

//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();

        for (int i = 0; i < n;)
        {
            int key = nums[i] + k;
            count++;
            int j = i + 1;
            while (j < n && nums[j] - nums[i] <= k) j++;
            i = j;
        }

        return count;
    }
};
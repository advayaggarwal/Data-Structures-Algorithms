class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        return help(nums, minK, maxK);
    }

    long long help(vector<int>&nums, int minK, int maxK)
    {
        int i = 0, j = 0, n = nums.size(), mini = INT_MAX, maxi = INT_MIN; myn
        multiset<int>maxHeap;
        multiset<int>minHeap;
        long long ans = 0;
        while (j < n)
        {
            maxHeap.insert(-nums[j]);
            minHeap.insert(nums[j]);
            maxi = -(*maxHeap.begin());
            mini = *(minHeap.begin());

            while ((i <= j) && (mini < minK or maxi > maxK))
            {
                auto it = minHeap.find(nums[i]);
                if (it != minHeap.end()) minHeap.erase(it);

                it = maxHeap.find(-nums[i]);
                if (it != maxHeap.end()) maxHeap.erase(it);

                maxi = -(*maxHeap.begin());
                mini = *minHeap.begin();

                i++;
            }

            j++;

            if (mini == minK && maxi == maxK)    ans++;
        }

        return ans;
    }
};
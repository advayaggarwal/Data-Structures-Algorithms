//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<long long>prefixSum(n);
        prefixSum[0] = nums[0];
        long long totalSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + 1LL * nums[i];
            totalSum += 1LL * nums[i];
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            long long forwardSum = prefixSum[i];
            long long backwardSum = totalSum - forwardSum;
            if (forwardSum >= backwardSum)    ans++;
        }

        return ans;
    }
};

//Smart way to calculate prefix sum
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long sumFromBack(0), sumFromFront(0);
        for (auto& i : nums)     sumFromBack += i;

        int n(size(nums)), res(0);
        for (auto i = 0; i < n - 1; i++) {

            sumFromFront += nums[i]; // sum of the first i + 1 elements
            sumFromBack -= nums[i]; // sum of the last n - i - 1 elements.
            if (sumFromFront >= sumFromBack)  res++;
        }
        return res;
    }
};
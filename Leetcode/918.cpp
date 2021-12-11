//Using Kadane's Algorithm
//Reference - https://www.youtube.com/watch?v=kd0-hUwISDo
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int n = nums.size();

        int maxSum = kadane(nums); //Finding max subarray sum without considering array as circular

        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
            nums[i] = -nums[i]; //Negating the elements to find min subarray sum
        }

        //Finding the min subarray sum - find Max subarray sum of nums by negating all the elements and then make it negative
        int minSum = kadane(nums);
        minSum = -minSum;

        if (totalSum == minSum)  return maxSum; //it means whole array is negative, so return the maxSum

        return max(maxSum, totalSum - minSum);
    }

    int kadane(vector<int>&nums)
    {
        int maxSum = INT_MIN;
        int sum = 0;

        for (int num : nums)
        {
            sum += num;

            if (sum > maxSum)    maxSum = sum;
            if (sum < 0) sum = 0;
        }

        return maxSum;
    }
};

//Shorter code - Kadane's Algorithm
int maxSubarraySumCircular(vector<int>& A) {
    int total = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
    for (int& a : A) {
        curMax = max(curMax + a, a);
        maxSum = max(maxSum, curMax); //maximum subarray sum
        curMin = min(curMin + a, a);
        minSum = min(minSum, curMin); //minimum subarray sum
        total += a;
    }
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum; //if all the values are negative return maxSum
}
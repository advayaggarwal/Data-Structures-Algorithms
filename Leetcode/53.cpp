//Brute Force
//Time complexity - O(n^3)
//Space complexity - O(1)
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int n = nums.size();

		int ans = INT_MIN;

		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				int sum = 0;
				for (int k = i; k <= j; k++)
				{
					sum += nums[k];
				}

				ans = max(ans, sum);
			}
		}

		return ans;
	}
};

//Brute Force with little optimisation
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int n = nums.size();

		int ans = INT_MIN;

		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = i; j < n; j++)
			{
				sum += nums[j];
				ans = max(ans, sum);
			}
		}

		return ans;
	}
};

//Kadane's Algorithm
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int n = nums.size();

		int maxSum = INT_MIN;
		int currentSum = 0;

		for (int i = 0; i < n; i++)
		{
			currentSum = max(nums[i], currentSum + nums[i]);
			//i.e. shall we start the sequence from i or include it in previous sequence
			maxSum = max(maxSum, currentSum);
		}

		return maxSum;
	}
};

//OR
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int n = nums.size();

		int maxSum = INT_MIN;
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += nums[i];

			if (sum > maxSum)	maxSum = sum;
			if (sum < 0) sum = 0;
		}

		return maxSum;
	}
};
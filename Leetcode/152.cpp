//Brute Force
//Time complexity - O(n^2)

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int product = 1;
		int ans = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				product  *= nums[j];
				ans = max(product, ans);
			}
			product = 1;
		}
		return ans;
	}
};


//Inspiration from Kadane's Algo
//Time complexity - O(n)

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int ans = nums[0], max_ending_here = nums[0], min_ending_here = nums[0];
		for (int i = 1; i < n; i++)
		{
			int temp = max_ending_here;
			max_ending_here = max({nums[i], nums[i]*max_ending_here, nums[i]*min_ending_here}); //if we want max of more than 2 elements we've to use list{}
			min_ending_here = min({nums[i], nums[i]*temp, nums[i]*min_ending_here});
			ans = max(ans, max_ending_here);
		}
		return ans;
	}
};
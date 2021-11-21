//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int ans = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int product = 1;
			for (int j = i; j < n; j++)
			{
				product  *= nums[j];
				ans = max(product, ans);
			}
		}

		return ans;
	}
};


//Inspiration from Kadane's Algo
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int ans = nums[0], max_ending_here = nums[0], min_ending_here = nums[0];
		for (int i = 1; i < n; i++)
		{
			int temp = max_ending_here;
			max_ending_here = max({nums[i], nums[i]*max_ending_here, nums[i]*min_ending_here});
			min_ending_here = min({nums[i], nums[i]*temp, nums[i]*min_ending_here});
			ans = max(ans, max_ending_here);
		}
		return ans;
	}
};

/*
There are 2 possibilities - either the number of -ve numbers is even or odd.

1. If they are even, then obviously we would want to include all of them(in fact the whole array(unless for zeros)) to maximise the product. This is because multiplying an even number of -ve numbers would make the result +ve.

2. If they are odd, then we would want to exclude at most(to maximise the product) one -ve number from our product. So, now the question is, which -ve number to exclude? There are 2 possibilities - first -ve num or last -ve num.

a. Note that, you cannot exclude a -ve number that is not the first or the last, because, if you do so, you will need to exclude all(because you are breaking the product at this point) other -ve nums following that -ve number and then that needn't result in the maximum product.

b. Remember, that our goal is to leave out only 1 -ve number so that we can maximise our product.

c. Note: We are leaving out one -ve number, so that we are able to make the number of -ve nums even. Having said all that, now the question is whether to exclude the first -ve num or the last -ve num in the array. We can only know the answer by trying both.

d. By taking the product from the beginning of the array, you forcefully include the first -ve number and exclude the last -ve number

e. vice-versa for taking the product from the end

To further explain 2d,e, let me take an example:

Assume the array has an odd number of -ve nums. The first -ve num is -2 and the last -ve num is -3. So the array is .....-2.......-3.......
The maximum product can either be made of all numbers from the beginning of the array to the first non-zero number just before -3, or from the end of the array to the first non-zero number just after -2.

This is why we are considering two possible products, one from the beginning and one from the end.
But wait, you might be thinking, why we are still continuing to multiply even beyond -3(forward iteration) or beyond -2 (backward iteration). That's all actually waste, as the product is only going to increase in negativity beyond those points. The maximum is already updated, so this doesn't affect at all.
*/
class Solution {
public:
	int maxProduct(vector<int>& nums)
	{
		int n = nums.size();
		int ans = INT_MIN;
		int product = 1;

		for (int i = 0; i < n; i++)
		{
			product *= nums[i];
			ans = max(ans, product);
			if (product == 0)    product = 1;
		}
		product = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			product *= nums[i];
			ans = max(ans, product);
			if (product == 0)    product = 1;
		}

		return ans;
	}
};
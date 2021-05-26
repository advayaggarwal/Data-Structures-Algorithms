/*
Solution explanation
https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me
*/

//ALL ELEMENTS SHOULD BE UNIQUE

class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = (r - l) / 2 + l;
			int comparator = nums[mid];
			// Checking if both target and nums[mid] are on same side.
			if ((target < nums[0]) && (nums[mid] < nums[0]) || (target >= nums[0]) && (nums[mid] >= nums[0]))
				comparator = nums[mid];
			else
			{
				// Trying to figure out where nums[mid] is and making comparator as -INF or INF
				if (target < nums[0])
					comparator = -INFINITY;
				else
					comparator = INFINITY;

			}
			if (target == comparator) return mid;
			if (target > comparator)
				l = mid + 1;
			else
				r = mid - 1;

		}
		return -1;
	}
};


//Aditya Verma approach

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int start  = 0;
		int end = n - 1;

		int min = -1;
		while (start <= end)
		{
			if (nums[start] <= nums[end])
			{
				min = start;
				break;
			}

			int mid = start + (end - start) / 2;
			int prev = (mid - 1 + n) % n;
			int next = (mid + 1) % n;
			if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
			{
				min = mid;
				break;
			}

			else if (nums[start] <= nums[mid])    start = mid + 1;
			else end = mid - 1;
		}

		int index1 = lower_bound(nums.begin(), nums.begin() + min, target) - nums.begin();
		int index2 = lower_bound(nums.begin() + min, nums.end(), target) - nums.begin();
		if (index1 >= n || nums[index1] != target) index1 = -1;
		if (index2 >= n || nums[index2] != target)    index2 = -1;
		//cout<<index1<<" "<<index2;
		return max(index1, index2);

	}

};



//MyCodeSchool approach

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int low  = 0;
		int hi = n - 1;

		while (low <= hi)
		{
			int mid = low + (hi - low) / 2;

			if (nums[mid] == target)    return mid; //Found the target

			else if (nums[mid] >= nums[low]) //Left half if sorted
			{
				if (target >= nums[low] && target < nums[mid])    hi = mid - 1;
				else low = mid + 1;
			}
			else //Right half is sorted
			{
				if (target > nums[mid] && target <= nums[hi])  low = mid + 1;
				else hi = mid - 1;
			}
		}

		return -1;
	}

};
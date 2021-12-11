class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end) //smallest element will always lie in unsorted region
        {
            if (nums[start] <= nums[end])    return nums[start];
            int mid = start + (end - start) / 2;

            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;

            if (nums[mid] < nums[prev] && nums[mid] < nums[next])    return nums[mid];

            else if (nums[start] <= nums[mid]) //start ... mid is sorted
            {
                start = mid + 1;
            }

            else // when nums[mid] and nums[end] are same
            {
                end = mid - 1;
            }
        }

        return INT_MIN;
    }
};


class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start < end) //smallest element will always lie in unsorted region
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end]) //mid+1 ... end is unsorted
            {
                start = mid + 1;
            }

            else    end = mid;

        }

        return nums[start];
    }
};
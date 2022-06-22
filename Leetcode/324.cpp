//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)  return;
        sort(nums.begin(), nums.end());

        vector<int>res(n);
        int i = 1;
        for (int j = n - 1; j >= 0; j--)
        {
            res[i] = nums[j];
            i += 2;
            if (i >= n)  i = 0;
        }

        nums = res;
    }
};

//Quickselect
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2)   return;
        int median = quickSelect(nums, 0, n - 1, (n + 1) / 2);
        int s = 0, e = n - 1;
        int mid = (n + 1) / 2;
        vector<int>temp(n);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < median)    temp[s++] = nums[i];
            else if (nums[i] > median)   temp[e--] = nums[i];
        }

        while (s < mid)  temp[s++] = median;
        while (e >= mid) temp[e--] = median;

        int smallStart = mid - 1, largeStart = n - 1;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)    nums[i] = temp[smallStart--];
            else nums[i] = temp[largeStart--];
        }
    }

    int quickSelect(vector<int>&nums, int start, int end, int k)
    {
        if (start <= end)
        {
            int pi = partition(nums, start, end);
            if (pi == k) return nums[pi];
            else if (pi < k) return quickSelect(nums, pi + 1, end, k);
            else return quickSelect(nums, start, pi - 1, k);
        }

        return INT_MAX;
    }

    int partition(vector<int>&nums, int start, int end)
    {
        int pi = start - 1;
        int pivot = nums[end];

        for (int i = start; i <= end; i++)
        {
            if (nums[i] <= pivot)
            {
                pi++;
                swap(nums[pi], nums[i]);
            }
        }

        return pi;
    }
};
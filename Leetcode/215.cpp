#include<bits/stdc++.h>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { //average O(n)
        int h = nums.size() - 1;
        int l = 0;
        k = nums.size() - k + 1;
        return quickselect(nums, l, h, k);

    }

    int quickselect(vector<int>&nums, int l, int h, int k)
    {
        if (l <= h)
        {
            int index = partition(nums, l, h);
            if (index == k - 1)    return nums[index];
            else if (index > k - 1)
            {
                return quickselect(nums, l, index - 1, k);
            }
            else return quickselect(nums, index + 1, h, k);
        }

        return -1;
    }

    int partition(vector<int>&nums, int l, int h)
    {
        int pivot = nums[h];
        int i = l - 1;
        for (int j = l; j < h; j++)
        {
            if (nums[j] <= pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[h]);
        return i + 1; //index of pivot
    }
};
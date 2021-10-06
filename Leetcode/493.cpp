//Time complexity - O(N*logN)
//Space complexity - O(N)
//Using merge sort, same as inversion count
#define vi vector<int>
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }

    int mergeSort(vi &nums, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;

            int c1 = mergeSort(nums, l, mid);
            int c2 = mergeSort(nums, mid + 1, r);

            int c3 = merge(nums, l, mid, r);

            return c1 + c2 + c3;
        }

        return 0;
    }

    int merge(vi &nums, int l, int mid, int r)
    {
        int count = 0;
        int j = mid + 1;
        for (int i = l; i <= mid; i++)
        {
            while (j <= r and nums[i] > 2LL * nums[j]) j++;

            count += (j - (mid + 1));
        }

        vi temp;
        int i = l;
        j = mid + 1;
        while (i <= mid and j <= r)
        {
            if (nums[i] < nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else temp.push_back(nums[j++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= r)   temp.push_back(nums[j++]);

        for (int i = l, k = 0; i <= r; i++, k++) nums[i] = temp[k];

        return count;
    }
};
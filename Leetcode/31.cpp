//Time complexity - O(N*logN)
//Space complexity - O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)    return;
        int i;
        for (i = n - 1; i > 0; i--) //O(N)
        {
            if (nums[i] > nums[i - 1])
            {
                break;
            }
        }
        int smallest_so_far = i;
        if (i != 0) //O(N)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ( (nums[j] > nums[i - 1]) && (nums[j] < nums[smallest_so_far])) smallest_so_far = j;
            }
            swap(nums[i - 1], nums[smallest_so_far]);
        }
        sort(nums.begin() + i, nums.end()); //O(N*logN)

    }
};



/*

We need to find the first pair of two successive numbers a[i] and a[i−1], from the right, which satisfy a[i] > a[i-1].
Now, no rearrangements to the right of a[i-1] can create a larger permutation since that subarray consists of numbers in descending order.
Thus, we need to rearrange the numbers to the right of a[i-1] including itself.
Now, what kind of rearrangement will produce the next larger number? We want to create the permutation just larger than the current one.
Therefore, we need to replace the number a[i-1] with the number which is just larger than itself among the numbers lying to its right
section, say a[j].
We swap the numbers a[i-1] and a[j]. We now have the correct number at index i-1. But still the current permutation isn't the
permutation that we are looking for. We need the smallest permutation that can be formed by using the numbers only to the right of a[i-1].
Therefore, we need to place those numbers in ascending order to get their smallest permutation.
But, recall that while scanning the numbers from the right, we simply kept decrementing the index until we found the pair
a[i] and a[i−1] where, a[i] > a[i-1]. Thus, all numbers to the right of a[i-1] were already sorted in descending order.
Furthermore, swapping a[i-1] and a[j] didn't change that order. Therefore, we simply need to reverse the numbers following a[i-1]
to get the next smallest lexicographic permutation.

*/


//Shortcut for above code as we know that from index i to n-1 array is in decreasing order and
//also no need to sort(we can sort by simply reversing the i to n-1 part)
//Time complexity - O(N)
//Space complexity - O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)    return;
        int i;
        for (i = n - 1; i > 0; i--) //O(N)
        {
            if (nums[i] > nums[i - 1])
            {
                break;
            }
        }
        if (i != 0) //O(N)
        {
            int j = i;
            while (j < n && nums[j] > nums[i - 1]) j++;
            j--;
            swap(nums[i - 1], nums[j]);
        }
        reverse(nums.begin() + i, nums.end());

    }
};

//We can start second for loop from last, and find the first element greater than the i-1 th element, then swap them

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)    return;
        int i;
        for (i = n - 1; i > 0; i--) //O(N)
        {
            if (nums[i] > nums[i - 1])
            {
                break;
            }
        }
        if (i != 0) //O(N)
        {
            int j;
            for (j = n - 1; j >= i; j--)
            {
                if (nums[j] > nums[i - 1])
                {
                    break;
                }
            }
            swap(nums[i - 1], nums[j]);


        }
        reverse(nums.begin() + i, nums.end());

    }
};


//Time complexity - O(N)
//Space complexity - O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)    return;
        int i;
        for (i = n - 1; i > 0; i--) //O(N)
        {
            if (nums[i] > nums[i - 1])
            {
                int idx = lower_bound_index(i, n - 1, nums[i - 1], nums); //lower bound will be called just once
                swap(nums[i - 1], nums[idx]);
                break;
            }
        }

        reverse(nums.begin() + i, nums.end());

    }

    int lower_bound_index(int low, int high, int key, vector<int>&nums)
    {
        int res = low;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= key)
            {
                high = mid - 1;
            }
            else
            {
                res = mid;
                low = mid + 1;
            }
        }

        return res;
    }

};

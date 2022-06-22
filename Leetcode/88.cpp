//Time complexity - O(m+n)
//Space complexity - O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])  nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }

        while (i >= 0)   nums1[k--] = nums1[i--];
        while (j >= 0)   nums1[k--] = nums2[j--];
    }
};

/*
This code relies on the simple observation that once all of the numbers from nums2 have been merged into nums1,
the rest of the numbers in nums1 that were not moved are already in the correct place.
*/
//Time complexity - O(m+n)
//Space complexity - O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])  nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }

        while (j >= 0)   nums1[k--] = nums2[j--];
    }
};
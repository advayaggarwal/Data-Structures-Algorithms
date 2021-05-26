//Time complexity - O(m+n)
//Space complexity - O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>total(m + n);
        int i = 0, j = 0, k = 0;
        while (j < m && k < n)
        {
            if (nums1[j] <= nums2[k])  total[i++] = nums1[j++];

            else total[i++] = nums2[k++];
        }

        while (j < m)  total[i++] = nums1[j++];
        while (k < n)  total[i++] = nums2[k++];


        if ((m + n) & 1) return (double)total[(m + n) / 2];
        else return (total[(m + n) / 2] + total[(m + n) / 2 - 1]) / 2.0;
    }
};


//Time complexity - O(log(min(m,n)))
//Space complexity - O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
        {
            swap(nums1, nums2);
            swap(m, n);
        }

        int low = 0;
        int high = m;
        while (low <= high)
        {
            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n) / 2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == m ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n ? INT_MAX : nums2[cut2];

            if (l1 > r2)
            {
                high  = cut1 - 1;
            }
            else if (l2 > r1)
            {
                low = cut1 + 1;
            }
            else
            {
                if ((m + n) & 1)
                {
                    return double(min(r1, r2));
                }
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }

        return -1;
    }
};
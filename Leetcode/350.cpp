//Time complexity - O(nlogn + mlogm)
//Space complexity - O(1), not considering output vector
// 2 pointer approach
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int>res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size(), m = nums2.size();

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])    i++;
            else j++;
        }

        return res;

    }
};


//Time complexity - O(n+m)
//Space complexity - O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int>res;

        unordered_map<int, int>freq;

        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++)  freq[nums1[i]]++;

        for (int i = 0; i < m; i++)
        {
            if (freq.find(nums2[i]) != freq.end() && freq[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }

        return res;

    }
};
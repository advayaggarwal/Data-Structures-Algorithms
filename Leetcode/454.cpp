//Time complexity - O(n^4)
//Space complexity - O(1)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int n = nums1.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0)    count++;
                    }
                }
            }
        }

        return count;
    }
};

//Time complexity - O(n^3)
//Space complexity - O(n)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int n = nums1.size();
        int count = 0;

        unordered_map<int, int>m;
        for (int i = 0; i < n; i++)  m[nums4[i]]++;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    int req = -nums1[i] - nums2[j] - nums3[k];
                    if (m.count(req) > 0)    count += m[req];
                }
            }
        }

        return count;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int n = nums1.size();
        int count = 0;

        unordered_map<int, int>m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = nums3[i] + nums4[j];
                m[sum]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int req = -nums1[i] - nums2[j];
                if (m.count(req) > 0)    count += m[req];
            }
        }

        return count;
    }
};
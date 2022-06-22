//LIS using DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        return nums.size() - longestBitonicSequence(nums, nums.size());
    }

    int longestBitonicSequence(vector<int>& arr, int n)
    {
        vector<int>dp1(n, 1), dp2(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && dp1[i] < dp1[j] + 1)    dp1[i] = dp1[j] + 1;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1)    dp2[i] = dp2[j] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            //Note: for the mountain array to be valid, we need to only consider peaks where dp1[i] > 1 and dp2[i] > 1.
            //see dp1 says that longest increasing subseq from left to that element
            // and if the value is 1 that simply means there are no elements to its left
            //the same way with dp2 which says about the longest increasing subseq from right to left
            // and if the value is 1 that simply means there are no elements to its right
            // the value is 1 coz we are counting that particular element as well
            if (dp1[i] > 1 && dp2[i] > 1)   ans = max(ans, dp1[i] + dp2[i] - 1);
        }

        return ans;
    }
};

//LIS using Binary Search
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        return nums.size() - longestBitonicSequence(nums, nums.size());
    }

    int longestBitonicSequence(vector<int>& arr, int n)
    {
        vector<int>dp1(n, 1), dp2(n, 1);
        vector<int>lis;
        for (int i = 0; i < n; i++)
        {
            auto index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            if (index == lis.size())    lis.push_back(arr[i]);
            else lis[index] = arr[i];

            dp1[i] = lis.size();
        }

        lis.clear();

        for (int i = n - 1; i >= 0; i--)
        {
            auto index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            if (index == lis.size())    lis.push_back(arr[i]);
            else lis[index] = arr[i];

            dp2[i] = lis.size();
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp1[i] > 1 && dp2[i] > 1)   ans = max(ans, dp1[i] + dp2[i] - 1);
        }

        return ans;
    }
};
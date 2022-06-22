//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int totalSteps(vector<int>& nums)
    {
        int count = 0;
        while (!nonDecreasing(nums))
        {
            count++;
            vector<int>temp;
            temp.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i - 1] > nums[i]) continue;
                temp.push_back(nums[i]);
            }

            nums = temp;
        }

        return count;
    }

    bool nonDecreasing(vector<int>&nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1]) return false;
        }

        return true;
    }
};

//Using Monotonic Stack
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int totalSteps(vector<int>& nums)
    {
        int ans = 0, n = nums.size();
        stack<int>st;
        vector<int>dp(n); //dp[i] denotes number of elements it will delete to its right
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i] > nums[st.top()])
            {
                dp[i] = max(dp[i] + 1, dp[st.top()]);
                st.pop();
            }

            ans = max(ans, dp[i]);
            st.push(i);
        }

        return ans;
    }
};
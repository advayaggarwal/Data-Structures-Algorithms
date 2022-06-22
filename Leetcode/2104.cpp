//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums)
    {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int minEle = INT_MAX, maxEle = INT_MIN;
            for (int j = i; j < n; j++)
            {
                minEle = min(minEle, nums[j]);
                maxEle = max(maxEle, nums[j]);
                ans += maxEle - minEle;
            }
        }

        return ans;
    }
};

//Using Stack
//add nums[i]*no of subarrays in which nums[i] is max, and subtract nums[i]*no of subarrays in which nums[i] is min
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums)
    {
        int n = nums.size();
        long long ans = 0;
        stack<int>st;

        //nums[i] is minimum
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n or nums[st.top()] > nums[i]))
            {
                int j = st.top();
                st.pop();
                int k = st.empty() ? - 1 : st.top();
                ans -= nums[j] * 1LL * (i - j) * (j - k);
            }
            st.push(i);
        }

        st = stack<int>(); // clearing the stack

        //nums[i] is maximum
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n or nums[st.top()] < nums[i]))
            {
                int j = st.top();
                st.pop();
                int k = st.empty() ? - 1 : st.top();
                ans += nums[j] * 1LL * (i - j) * (j - k);
            }
            st.push(i);
        }

        return ans;
    }
};
//Next Greater Element using stack
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int>s;
        int n = nums.size();
        vector<int>ans(n);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i % n])   s.pop();

            if (!s.empty())  ans[i % n] = s.top();
            else ans[i % n] = -1;
            s.push(nums[i % n]);
        }

        return ans;
    }
};
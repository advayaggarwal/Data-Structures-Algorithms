//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        int n = nums.size();
        priority_queue<int>maxHeap;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int no = nums[i] % 2 ? 2 * nums[i] : nums[i];
            maxHeap.push(no);
            mini = min(mini, no);
        }

        int ans = INT_MAX;
        while (maxHeap.top() % 2 == 0)
        {
            ans = min(ans, maxHeap.top() - mini);
            mini = min(mini, maxHeap.top() / 2);
            maxHeap.push(maxHeap.top() / 2);
            maxHeap.pop();
        }

        return min(ans, maxHeap.top() - mini);
    }
};
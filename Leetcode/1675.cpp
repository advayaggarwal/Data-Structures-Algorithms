/*
Intution - Increase the minimum and decrease the maximum to minimise the deviation
Observation - Even number can't be increased(as we can only do multiplication by 2) and Odd number can't be decreased(as we can only do division by 2)
Once the minimum number is even and maximum number is odd -> this is the terminating condition
Instead of checking both the conditions, we can make every number even, it won't change the answer
As soon as maximum number is odd, we can stop
We can do vice versa also, but it's difficult to make even number odd (have to do multiple divisions by 2)
*/

//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        int n = nums.size(), mini = INT_MAX, ans = INT_MAX;
        priority_queue<int>maxHeap;

        //make every element as even
        for (int i = 0; i < n; i++)
        {
            int num = nums[i] & 1 ? nums[i] * 2 : nums[i];
            maxHeap.push(num);
            mini = min(mini, num);
        }

        //while max element is even, once it's odd we can't decrease it further
        while (maxHeap.top() % 2 == 0)
        {
            int max_element = maxHeap.top();
            maxHeap.pop();
            ans = min(ans, max_element - mini);
            mini = min(mini, max_element / 2);
            maxHeap.push(max_element / 2);
        }

        return min(ans, maxHeap.top() - mini);
    }
};
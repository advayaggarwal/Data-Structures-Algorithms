/*
    Time complexity - O(n)
    Space complexity - O(n)

    a    b c d e f g

    <-S1->   S1 = a+b
    <-S2------->  S2 = a+b+c+d+e

    Lets suppose (c+d+e)%k == 0
    then
    (S2-S1)%k == 0
    Hence S2%k == S1%k, means if we have already seen this remainder
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int>m; //{sum, index}
        m[0] = -1;
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (m.count(sum % k) && i - m[sum % k] > 1)  return true; //if present and size is >= 2
            if (!m.count(sum % k)) m[sum % k] = i;
        }

        return false;
    }
};
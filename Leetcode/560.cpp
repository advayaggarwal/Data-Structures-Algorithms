//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        unordered_map<int, int>m;
        int sum = 0;
        int count = 0;
        //m[0] = 1;
        while (i < n)
        {
            sum += nums[i];

            if (sum == k)  count++;
            if (m.find(sum - k) != m.end())
            {
                count += m[sum - k];
            }


            m[sum]++;
            i++;

        }
        return count;

    }
};
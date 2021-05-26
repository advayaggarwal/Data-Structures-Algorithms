class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate;
        int count = 0;
        for (int &num : nums)
        {
            if (count == 0)    candidate = num;

            count += candidate == num ? 1 : -1;
        }

        return candidate;
    }
};
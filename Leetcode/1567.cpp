//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        int ans = 0;
        int positive = 0, negative = 0;

        for (int x : nums)
        {
            if (x == 0)
            {
                positive = 0;
                negative = 0;
            }

            else if (x > 0)
            {
                positive++;
                negative = negative == 0 ? 0 : negative + 1;
            }

            else
            {
                int temp = positive;
                positive = negative == 0 ? 0 : negative + 1;
                negative = temp + 1;
            }

            ans = max(ans, positive);
        }

        return ans;
    }
};
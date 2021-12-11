//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 3)   return false;

        int f = INT_MAX, s = INT_MAX; // f-first, s-second, t-third

        //We are maintaining the property that first is always less than second(first being the smallest from left) and,
        //in this process if we get third which is greater than both, then we got the triplet

        for (int t : nums)
        {
            if (t <= f)   f = t;

            else if (t <= s)  s = t;

            else return true;
        }

        return false;
    }
};
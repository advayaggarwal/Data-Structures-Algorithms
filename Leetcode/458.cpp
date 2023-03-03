//Time complexity - O(logn)
//Space complexity - O(1)
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int periods = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(periods + 1));
    }
};
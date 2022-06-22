//Time complexity - O(1)
//Space complexity - O(1)
class Solution {
public:
    int countOdds(int low, int high)
    {
        int totalNo = high - low + 1;
        int ans = totalNo / 2;
        if (totalNo & 1)
        {
            if (low & 1) return totalNo / 2 + 1;
        }

        return ans;
    }
};
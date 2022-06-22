//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int maxProfit = 0;
        int minSoFar = INT_MAX;

        for (int price : prices)
        {
            minSoFar = min(minSoFar, price);
            maxProfit = max(maxProfit, price - minSoFar);
        }

        return maxProfit;
    }
};
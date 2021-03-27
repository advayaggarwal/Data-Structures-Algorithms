class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)  return 0;
        int maxprofit = 0;
        int min_so_far = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min_so_far)  min_so_far = prices[i];
            else if (prices[i] - min_so_far > maxprofit)    maxprofit = prices[i] - min_so_far;
        }

        return maxprofit;

    }
};
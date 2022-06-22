//Compare consecutive slopes
//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices)
    {
        if (stockPrices.size() == 1) return 0;
        sort(stockPrices.begin(), stockPrices.end());
        long long prevNum = stockPrices[1][1] - stockPrices[0][1], prevDen = stockPrices[1][0] - stockPrices[0][0];
        int ans = 1; //used 1 slope by joining 1st 2 points
        int n = stockPrices.size();
        for (int i = 2; i < n; i++)
        {
            long long num = stockPrices[i][1] - stockPrices[i - 1][1];
            long long den = stockPrices[i][0] - stockPrices[i - 1][0];

            if ((prevNum * den) != (num * prevDen))
            {
                ans++;
                prevNum = num;
                prevDen = den;
            }
        }
        return ans;
    }
};
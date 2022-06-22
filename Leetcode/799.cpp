//Time complexity - O(r*c)
//Space complexity - O(r*c)
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>>dp(102, vector<double>(102));
        dp[0][0] = (double) poured;
        for (int r = 0; r < query_row; r++)
        {
            for (int c = 0; c <= r; c++)
            {
                double q = (dp[r][c] - 1) / 2.0;
                if (q > 0)
                {
                    dp[r + 1][c] += q;
                    dp[r + 1][c + 1] += q;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};

//Space optimised DP
//Time complexity - O(r*c)
//Space complexity - O(c)
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double>prev(102);
        prev[0] = (double) poured;
        for (int r = 0; r < query_row; r++)
        {
            vector<double>curr(102);
            for (int c = 0; c <= r; c++)
            {
                double q = (prev[c] - 1) / 2.0;
                if (q > 0)
                {
                    curr[c] += q;
                    curr[c + 1] += q;
                }
            }

            prev = curr;
        }

        return min(1.0, prev[query_glass]);
    }
};
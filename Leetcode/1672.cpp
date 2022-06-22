//Time complexity - O(m*n)
//Space complexity - O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts)
    {
        int m = accounts.size(), n = accounts[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)  sum += accounts[i][j];

            ans = max(ans, sum);
        }

        return ans;
    }
};
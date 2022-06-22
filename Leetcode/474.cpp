//Top Down DP
//Time complexity - O(m*n*sz), where sz is the size of strs
//Space complexity - O(m*n*sz)
class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int sz = strs.size();
        vector<pair<int, int>>count(sz);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < sz; i++)    count[i] = countZeroAndOne(strs[i]);

        return helper(0, m, n, count);
    }

    pair<int, int> countZeroAndOne(string &s)
    {
        int zero = 0, one = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') zero++;
            else one++;
        }

        return {zero, one};
    }

    int helper(int i, int m, int n, vector<pair<int, int>>&count)
    {
        if (i == count.size())   return 0;
        if (dp[i][m][n] != -1)   return dp[i][m][n];
        int take = INT_MIN, notTake = helper(i + 1, m, n, count);

        if (count[i].first <= m && count[i].second <= n) take = 1 + helper(i + 1, m - count[i].first, n - count[i].second, count);

        return dp[i][m][n] = max(take, notTake);
    }
};

//Bottom Up DP
//Time complexity - O(m*n*sz), where sz is the size of strs
//Space complexity - O(m*n*sz)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int sz = strs.size();
        vector<pair<int, int>>count(sz);
        for (int i = 0; i < sz; i++) count[i] = countZeroAndOne(strs[i]);

        vector<vector<vector<int>>>dp(sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = sz - 1; i >= 0; i--)
        {
            for (int mm = 0; mm <= m; mm++)
            {
                for (int nn = 0; nn <= n; nn++)
                {
                    int take = INT_MIN, notTake = dp[i + 1][mm][nn];

                    if (count[i].first <= mm && count[i].second <= nn) take = 1 + dp[i + 1][mm - count[i].first][nn - count[i].second];

                    dp[i][mm][nn] = max(take, notTake);
                }
            }
        }

        return dp[0][m][n];
    }

    pair<int, int> countZeroAndOne(string &s)
    {
        int zero = 0, one = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') zero++;
            else one++;
        }

        return {zero, one};
    }
};

//Bottom Up DP with space optimisation
//Time complexity - O(m*n*sz), where sz is the size of strs
//Space complexity - O(m*n)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int sz = strs.size();
        vector<pair<int, int>>count(sz);
        for (int i = 0; i < sz; i++) count[i] = countZeroAndOne(strs[i]);

        vector<vector<int>>curr(m + 1, vector<int>(n + 1)), next(m + 1, vector<int>(n + 1));
        for (int i = sz - 1; i >= 0; i--)
        {
            for (int mm = 0; mm <= m; mm++)
            {
                for (int nn = 0; nn <= n; nn++)
                {
                    int take = INT_MIN, notTake = next[mm][nn];

                    if (count[i].first <= mm && count[i].second <= nn) take = 1 + next[mm - count[i].first][nn - count[i].second];

                    curr[mm][nn] = max(take, notTake);
                }
            }

            next = curr;
        }

        return curr[m][n];
    }

    pair<int, int> countZeroAndOne(string &s)
    {
        int zero = 0, one = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') zero++;
            else one++;
        }

        return {zero, one};
    }
};
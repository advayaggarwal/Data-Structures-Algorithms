//Recursion
//Time complexity - O(3^n)
//Space complexity - O(n)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        return helper(0, days, costs, 0);
    }

    int helper(int i, vector<int>&days, vector<int>&costs, int lastDay)
    {
        if (i == days.size())    return 0;

        if (days[i] <= lastDay)  return helper(i + 1, days, costs, lastDay);
        else
        {
            return min({costs[0] + helper(i + 1, days, costs, days[i]), costs[1] + helper(i + 1, days, costs, days[i] + 6), costs[2] + helper(i + 1, days, costs, days[i] + 29)});
        }
    }
};

//Top Down DP
//Time complexity - O(n*396)
//Space complexity - O(n*396)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<vector<int>>dp(days.size() + 1, vector<int>(396, -1));
        return helper(0, days, costs, 0, dp);
    }

    int helper(int i, vector<int>&days, vector<int>&costs, int lastDay, vector<vector<int>>&dp)
    {
        if (i == days.size())    return 0;
        if (dp[i][lastDay] != -1)    return dp[i][lastDay];

        if (days[i] <= lastDay)  return dp[i][lastDay] = helper(i + 1, days, costs, lastDay, dp);
        else
        {
            return dp[i][lastDay] = min({costs[0] + helper(i + 1, days, costs, days[i], dp), costs[1] + helper(i + 1, days, costs, days[i] + 6, dp), costs[2] + helper(i + 1, days, costs, days[i] + 29, dp)});
        }
    }
};

//Bottom Up DP
//Time complexity - O(n*396)
//Space complexity - O(n*396)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<vector<int>>dp(days.size() + 1, vector<int>(396, INT_MAX));
        for (int i = 0; i < 396; i++)  dp[days.size()][i] = 0;

        for (int i = days.size() - 1; i >= 0; i--)
        {
            for (int lastDay = 395; lastDay >= 0; lastDay--)
            {
                if (days[i] <= lastDay)  dp[i][lastDay] = dp[i + 1][lastDay];
                else
                {
                    dp[i][lastDay] = min({costs[0] + dp[i + 1][days[i]], costs[1] + dp[i + 1][days[i] + 6]
                                          , costs[2] + dp[i + 1][days[i] + 29]
                                         });
                }
            }
        }

        return dp[0][0];
    }
};

//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int>dp(days.size() + 1, -1);
        return helper(0, days, costs, dp);
    }

    int helper(int i, vector<int>&days, vector<int>&costs, vector<int>&dp)
    {
        if (i == days.size())    return 0;
        if (dp[i] != -1)    return dp[i];

        //1 day pass
        int option1 = costs[0] + helper(i + 1, days, costs, dp);

        //7 day pass
        int j;
        for (j = i; j < days.size() && days[j] < days[i] + 7; j++);
        int option2 = costs[1] + helper(j, days, costs, dp);

        int k;
        for (k = i; k < days.size() && days[k] < days[i] + 30; k++);
        int option3 = costs[2] + helper(k, days, costs, dp);

        return dp[i] = min(option1, min(option2, option3));
    }
};

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int>dp(days.size() + 1, INT_MAX);
        dp[days.size()] = 0;

        for (int i = days.size() - 1; i >= 0; i--)
        {
            //1 day pass
            int option1 = costs[0] + dp[i + 1];

            //7 day pass
            int j;
            for (j = i; j < days.size() && days[j] < days[i] + 7; j++);
            int option2 = costs[1] + dp[j];

            int k;
            for (k = i; k < days.size() && days[k] < days[i] + 30; k++);
            int option3 = costs[2] + dp[k];

            dp[i] = min(option1, min(option2, option3));
        }

        return dp[0];
    }
};
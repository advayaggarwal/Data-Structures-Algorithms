//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        int op1 = helper(0, cost);
        int op2 = helper(1, cost);
        return min(op1, op2);
    }

    int helper(int index, vector<int>&cost)
    {
        if (index >= cost.size())    return 0;

        return dp[index] = cost[index] + min(helper(index + 1, cost), helper(index + 2, cost));
    }
};

//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int>dp(n + 1, -1);

        int op1 = helper(0, cost, dp);
        int op2 = helper(1, cost, dp);
        return min(op1, op2);
    }

    int helper(int index, vector<int>&cost, vector<int>&dp)
    {
        if (index >= cost.size())    return 0;

        if (dp[index] != -1)   return dp[index];

        int ans = cost[index];

        return dp[index] = ans + min(helper(index + 1, cost, dp), helper(index + 2, cost, dp));
    }
};

//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n), we need only 2 states i and i+1, so it can be done in O(1) space also
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int>dp(n + 2); //dp[i] denotes min cost to reach from index i to end

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};
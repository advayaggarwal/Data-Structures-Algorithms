//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        return min(helper(0, cost), helper(1, cost));
    }

    int helper(int i, vector<int>&cost)
    {
        if (i >= cost.size())    return 0;
        return cost[i] + min(helper(i + 1, cost), helper(i + 2, cost));
    }
};

//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int>dp(cost.size(), -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }

    int helper(int i, vector<int>&cost, vector<int>&dp)
    {
        if (i >= cost.size())    return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(helper(i + 1, cost, dp), helper(i + 2, cost, dp));
    }
};

//Bottom Up DP
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

//Bottom Up DP with space optimisation
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int next = 0, nextNext = 0;

        for (int i = cost.size() - 1; i >= 0; i--)
        {
            int curr = cost[i] + min(next, nextNext);
            nextNext = next;
            next = curr;
        }

        return min(next, nextNext);
    }
};
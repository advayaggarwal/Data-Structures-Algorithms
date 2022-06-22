//Recursion - can be converted to DP with time complexity = O(n^3)
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int n = costs.size();

        return helper(n - 1, n / 2, n / 2, costs);
    }

    int helper(int i, int a, int b, vector<vector<int>>& costs)
    {
        if (i < 0)
        {
            if (a == 0 && b == 0)    return 0;
            return INT_MAX;
        }

        int op1 = INT_MAX, op2 = INT_MAX;
        if (a > 0)   op1 = costs[i][0] + helper(i - 1, a - 1, b, costs);
        if (b > 0)   op2 = costs[i][1] + helper(i - 1, a, b - 1, costs);

        return min(op1, op2);
    }
};

//Greedy
//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int n = costs.size();

        int ans = 0;
        for (auto &cost : costs) ans += cost[0];

        sort(costs.begin(), costs.end(), [&](vector<int>&a, vector<int>&b) {
            return a[1] - a[0] < b[1] - b[0]; //difference should be smaller
        });

        for (int i = 0; i < n / 2; i++)    ans += (costs[i][1] - costs[i][0]);

        return ans;
    }
};
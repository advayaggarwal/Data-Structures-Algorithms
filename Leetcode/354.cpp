// LIS
//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(), envelopes.end());
        int previ = -1; //previous envelope selected
        return helper(0, envelopes, previ);
    }

    int helper(int i, vector<vector<int>>& envelopes, int previ)
    {
        if (i == envelopes.size())   return 0;

        int take = INT_MIN;
        int notTake = helper(i + 1, envelopes, previ);

        if (previ == -1 or (envelopes[i][0] > envelopes[previ][0] && envelopes[i][1] > envelopes[previ][1])) take = 1 + helper(i + 1, envelopes, i);

        return max(take, notTake);
    }
};

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        int previ = -1;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return helper(0, envelopes, previ, dp);
    }

    int helper(int i, vector<vector<int>>& envelopes, int previ, vector<vector<int>>&dp)
    {
        if (i == envelopes.size())   return 0;
        if (previ != -1 && dp[i][previ] != -1)  return dp[i][previ];

        int take = INT_MIN;
        int notTake = helper(i + 1, envelopes, previ, dp);

        if (previ == -1 or (envelopes[i][0] > envelopes[previ][0] && envelopes[i][1] > envelopes[previ][1])) take = 1 + helper(i + 1, envelopes, i, dp);

        int ans = max(take, notTake);
        if (previ != -1) dp[i][previ] = ans;
        return ans;
    }
};

//LIS using Binary Search
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>&a, vector<int>&b) {
            if (a[0] == b[0])    return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int>ans;

        for (auto &v : envelopes)
        {
            if (ans.size() == 0 or ans[ans.size() - 1] < v[1]) ans.push_back(v[1]);
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), v[1]) - ans.begin();
                ans[index] = v[1];
            }
        }

        return ans.size();
    }
};
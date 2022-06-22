//Time complexity - O(n)
//Space complexity - O(n)
//No need to make forbidden set, simply push forbidden values into visited set, so that we can't visit them
//farthest = max(x, forbidden) + a + b, Bezout's Identity
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x)
    {
        if (x == 0)  return 0;
        vector<vector<bool>>visited(2, vector<bool>(6001));
        int farthest = x + a + b;

        for (int &pos : forbidden)
        {
            visited[0][pos] = true;
            visited[1][pos] = true;
            farthest = max(farthest, pos + a + b);
        }


        queue<pair<int, int>>q; //{pos, direction}
        q.push({0, 0});
        visited[0][0] = true;
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int pos = q.front().first;
                int dir = q.front().second;
                q.pop();

                if (pos == x)    return steps;

                int nextPos = pos + a;
                if (nextPos <= farthest && !visited[1][nextPos])
                {
                    visited[1][nextPos] = true;
                    q.push({nextPos, 1});
                }

                if (dir == 1) //last step we took was forward, only then we can take backward step
                {
                    int backPos = pos - b;
                    if (backPos >= 0 && !visited[0][backPos])
                    {
                        visited[0][backPos] = true;
                        q.push({backPos, 0});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

//Top Down DP
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x)
    {
        unordered_set<int>forbid;
        for (int f : forbidden)  forbid.insert(f);
        vector<vector<int>>dp(6001, vector<int>(2, -1));
        int ans = minJumps(0, a, b, x, forbid, 0, dp);
        return ans >= 1e9 ? -1 : ans;
    }

    int minJumps(int index, int a, int b, int x, unordered_set<int>&forbid, int backwards, vector<vector<int>>&dp)
    {
        if (index == x)  return 0;
        if (index < 0 or index > 6000 or forbid.count(index))   return 1e9;
        if (dp[index][backwards] != -1)  return dp[index][backwards];

        //jumping forward
        dp[index][backwards] = 1 + minJumps(index + a, a, b, x, forbid, 0, dp);

        //jumping backward iff last jump was not backward
        if (!backwards)    dp[index][backwards] = min(dp[index][backwards], 1 + minJumps(index - b, a, b, x, forbid, 1, dp));

        return dp[index][backwards];
    }
};
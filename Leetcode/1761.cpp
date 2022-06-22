//Time complexity - O(n^3)
//Space complexity - O(n^2)
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>>adj(n + 1, vector<int>(n + 1));
        vector<int>degree(n + 1);

        for (auto e : edges)
        {
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
            degree[e[0]]++;
            degree[e[1]]++;
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    if (adj[i][j] && adj[j][k] && adj[k][i])
                    {
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
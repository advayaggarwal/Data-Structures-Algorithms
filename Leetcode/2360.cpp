//Time complexity - O(V+E)
//Space complexity - O(V+E)
class Solution {
public:
    int longestCycle(vector<int>& edges)
    {
        int n = edges.size();
        vector<int>adj(n), parent(n, -1);
        vector<bool>visited(n, false), dfs_visited(n, false);

        for (int i = 0; i < n; i++)  adj[i] = edges[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int cycle = 0;
                dfs(i, adj, parent, visited, dfs_visited, cycle);
                ans = max(ans, cycle + 1);
            }
        }

        return ans == 1 ? -1 : ans;
    }

    void dfs(int src, vector<int>&adj, vector<int>&parent, vector<bool>&visited, vector<bool>&dfs_visited, int &cycle)
    {
        visited[src] = true;
        dfs_visited[src] = true;

        int nbr = adj[src];
        if (nbr != -1)
        {
            if (!visited[nbr])
            {
                parent[nbr] = src;
                dfs(nbr, adj, parent, visited, dfs_visited, cycle);
            }

            else if (dfs_visited[nbr])
            {
                int curr_node = src;
                while (curr_node != -1 && curr_node != nbr)
                {
                    cycle++;
                    curr_node = parent[curr_node];
                }
            }
        }

        dfs_visited[src] = false;
    }
};
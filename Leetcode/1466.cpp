//Treat the graph as undirected.
//Start a dfs from the root, if you come across an edge in the forward direction, you need to reverse the edge.
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>>adj(n);
        for (auto c : connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }

        vector<bool>visited(n);

        return dfs(0, adj, visited);
    }

    int dfs(int src, vector<vector<int>>&adj, vector<bool>&visited)
    {
        visited[src] = true;
        int count = 0;

        for (int nbr : adj[src])
        {
            if (!visited[abs(nbr)])
            {
                count += dfs(abs(nbr), adj, visited) + (nbr > 0);
            }
        }

        return count;
    }
};
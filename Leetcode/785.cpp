class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(i, graph, visited, 1))  return false;
            }
        }

        return true;
    }

    bool dfs(int source, vector<vector<int>>& graph, vector<int>&visited, int color)
    {
        visited[source] = color;

        for (int nbr : graph[source])
        {
            if (visited[nbr] == 0)
            {
                if (!dfs(nbr, graph, visited, 3 - color))   return false;
            }

            else if (color == visited[nbr])   return false;
        }

        return true;
    }
};
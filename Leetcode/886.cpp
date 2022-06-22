class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<vector<int>>graph(n + 1);
        vector<int>visited(n + 1);
        for (auto &edge : dislikes)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 1; i <= n; i++)
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
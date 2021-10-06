//Cycle detection in Directed Graph
//Time complexity - O(V+E)
class Solution {
public:

    bool dfs(int source, vector<bool>&visited, vector<bool>&dfs_visited, vector<int>adj[])
    {
        visited[source] = true;
        dfs_visited[source] = true;

        for (int nbr : adj[source])
        {
            if (!visited[nbr])
            {
                if (dfs(nbr, visited, dfs_visited, adj))    return true;
            }

            else if (dfs_visited[nbr])  return true;
        }

        dfs_visited[source] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>adj[numCourses];

        vector<bool>visited(numCourses, false);
        vector<bool>dfs_visited(numCourses, false);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, dfs_visited, adj))  return false; //deadlock
            }
        }

        return true;
    }
};
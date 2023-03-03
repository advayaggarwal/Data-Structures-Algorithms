//Using BFS - Kahn's Algorithm
//Time complexity - O(V+E)
//Space complexity - O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>adj[numCourses];
        vector<int>indegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        vector<int>ans;
        int count = 0;

        bfs(0, numCourses, indegree, adj, count, ans);

        if (count != numCourses) return {};

        return ans;
    }

    void bfs(int node, int n, vector<int>&indegree, vector<int>adj[], int &count, vector<int>&ans)
    {
        queue<int>q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)  q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (int nbr : adj[node])
            {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }

            count++;
        }
    }
};

//Using DFS
//Time complexity - O(V+E)
//Space complexity - O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int>adj[numCourses], res;
        vector<bool>visited(numCourses), dfs_visited(numCourses);
        for (auto v : prerequisites)  adj[v[1]].push_back(v[0]);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i]) if (dfs(i, adj, visited, dfs_visited, res))  return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int source, vector<int> adj[], vector<bool> &visited, vector<bool> &dfs_visited, vector<int>&res)
    {
        visited[source] = true;
        dfs_visited[source] = true;

        for (int neigh : adj[source])
        {
            if (!visited[neigh])
            {
                if (dfs(neigh, adj, visited, dfs_visited, res)) return true;
            }

            else if (dfs_visited[neigh])    return true;
        }

        dfs_visited[source] = false;
        res.push_back(source);
        return false;
    }
};
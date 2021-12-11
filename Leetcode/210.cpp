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
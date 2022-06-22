//Applying BFS considering each node as root at a time
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>>adj(n);
        vector<int>height(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)  bfs(i, n, adj, height);

        int minHeight = *min_element(height.begin(), height.end());
        vector<int>res;
        for (int i = 0; i < n; i++)
        {
            if (height[i] == minHeight)  res.push_back(i);
        }

        return res;
    }

    void bfs(int src, int n, vector<vector<int>>&adj, vector<int>&height)
    {
        vector<int>dis(n, INT_MAX);
        queue<int>q;
        dis[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node])
            {
                if (dis[nbr] == INT_MAX)
                {
                    dis[nbr] = 1 + dis[node];
                    q.push(nbr);
                }
            }
        }

        height[src] = *max_element(dis.begin(), dis.end());
    }
};

//The basic idea is "keep deleting leaves layer-by-layer, until reach the root."
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n == 1)    return {0};
        vector<unordered_set<int>>adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        queue<int>q;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 1)    q.push(i); //pushing the leaves into the queue
        }

        while (n > 2)
        {
            int leaves = q.size(); //#leaves
            n -= leaves;

            for (int i = 0; i < leaves; i++)
            {
                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) //removing this leaf node from adj list of all other nodes
                {
                    adj[nbr].erase(node);
                    if (adj[nbr].size() == 1)    q.push(nbr);
                }
            }
        }

        vector<int>res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};
//Using DSU
//Time complexity - O(n+e)
//Space complexity - O(2*n)
class Solution {
public:

    int find(int x, vector<int> &leader)
    {
        if (leader[x] == -1) return x;

        return leader[x] = find(leader[x], leader);
    }

    void unionSet(int u, int v, vector<int>&leader, vector<int>&rank)
    {
        int l1 = find(u, leader);
        int l2 = find(v, leader);

        if (l1 != l2)
        {
            if (rank[l1] > rank[l2]) leader[l2] = l1;

            else if (rank[l1] < rank[l2])    leader[l1] = l2;

            else
            {
                leader[l1] = l2;
                rank[l2]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int e = connections.size(); //no of edges
        if (e < n - 1)  return -1; //we need at least n-1 edges to make graph connected

        vector<int>leader(n, -1);
        vector<int>rank(n, 1);

        int extra = 0;

        for (int i = 0; i < e; i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            int l1 = find(u, leader);
            int l2 = find(v, leader);

            if (l1 != l2)
            {
                unionSet(u, v, leader, rank);
            }

            else extra++;
        }

        int components = 0;

        for (int i = 0; i < n; i++)
        {
            if (find(i, leader) == i)    components++;
        }

        return extra >= components - 1 ? components - 1 : -1;
    }
};

//Using DFS
class Solution {
public:

    void dfs(int node, vector<bool>&visited, vector<int>adj[])
    {
        visited[node] = true;

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited, adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int e = connections.size();

        if (e < n - 1) return -1;

        vector<int>adj[n + 1];
        vector<bool>visited(n + 1, false);

        for (auto p : connections)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        int components = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj);
                components++;
            }
        }

        return components - 1;
    }
};
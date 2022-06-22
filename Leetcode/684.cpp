//Using Tarjan's Algorithm
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    set<vector<int>>bridge;
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int>adj[n + 1];

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int time = 0;
        vector<int>par(n + 1, -1), disc(n + 1, -1), low(n + 1, -1);
        dfs(1, adj, par, disc, low, time);

        vector<int>ans;
        for (auto &edge : edges)
        {
            if (bridge.count(edge) == 0) ans = edge;
        }

        return ans;
    }

    void dfs(int src, vector<int>adj[], vector<int>&par, vector<int>&disc, vector<int>&low, int &time)
    {
        disc[src] = low[src] = time;
        time++;

        for (int &nbr : adj[src])
        {
            if (disc[nbr] == -1)
            {
                par[nbr] = src;
                dfs(nbr, adj, par, disc, low, time);
                low[src] = min(low[src], low[nbr]);

                if (low[nbr] > disc[src])
                {
                    vector<int>b1 = {src, nbr}, b2 = {nbr, src};
                    bridge.insert(b1);
                    bridge.insert(b2);
                }
            }

            else if (nbr != par[src])    low[src] = min(low[src], disc[nbr]);
        }
    }
};

//Using DSU with path compression and union by rank
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int>ans, leader(n + 1, -1), rank(n + 1, 1);

        for (auto &edge : edges)
        {
            int l1 = find(edge[0], leader);
            int l2 = find(edge[1], leader);

            if (l1 == l2)    ans = edge;
            else Union(edge[0], edge[1], leader, rank);
        }

        return ans;
    }

    int find(int x, vector<int>&leader)
    {
        if (leader[x] == -1) return x;
        return leader[x] = find(leader[x], leader);
    }

    void Union(int x, int y, vector<int>&leader, vector<int>&rank)
    {
        int l1 = find(x, leader);
        int l2 = find(y, leader);

        if (rank[l1] < rank[l2]) leader[l1] = l2;
        else if (rank[l1] > rank[l2])    leader[l2] = l1;
        else
        {
            leader[l1] = l2;
            rank[l2]++;
        }
    }
};
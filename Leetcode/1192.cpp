//Brute Force - Finding all the cycles and removing all the edges that are the part of cycle
//Remaining edges will be critical
//Time complexity - O(n^2*logn)
//Space complexity - O(n)
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<int>adj[n];
        for (vector<int> &e : connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>par(n, -1);
        vector<bool>visited(n, false);
        set<pair<int, int>>cycles; //{start, end}
        dfs(0, visited, par, adj, cycles);

        set<pair<int, int>>nonCritical;
        vector<vector<int>>critical;
        for (auto &p : cycles)
        {
            int start = p.first, end = p.second;
            nonCritical.insert({end, start});
            while (start != end && end != -1)
            {
                nonCritical.insert({end, par[end]});
                end = par[end];
            }
        }

        for (int i = 0; i < connections.size(); i++)
        {
            if (!nonCritical.count({connections[i][0], connections[i][1]}) && !nonCritical.count({connections[i][1], connections[i][0]}))
            {
                critical.push_back(connections[i]);
            }
        }

        return critical;
    }

    void dfs(int src, vector<bool>&visited, vector<int>&par, vector<int>adj[], set<pair<int, int>>&cycles)
    {
        visited[src] = true;

        for (int &nbr : adj[src])
        {
            if (!visited[nbr])
            {
                par[nbr] = src;
                dfs(nbr, visited, par, adj, cycles);
            }

            else if (nbr != par[src]) //contains cycle
            {
                if (!cycles.count({nbr, src}) && !cycles.count({src, nbr}))   cycles.insert({nbr, src});
            }
        }
    }
};

//Optimal - Tarjan's Algorithm - Finding bridges
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<int>adj[n];
        for (vector<int> &e : connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>par(n, -1), low(n), disc(n, -1);
        vector<vector<int>>critical;
        int time = 0;
        dfs(0, par, adj, low, disc, critical, time);
        return critical;
    }

    void dfs(int src, vector<int>&par, vector<int>adj[], vector<int>&low, vector<int>&disc, vector<vector<int>>&critical, int &time)
    {
        disc[src] = low[src] = time;
        time++;

        for (int &nbr : adj[src])
        {
            if (disc[nbr] == -1) //not visited
            {
                par[nbr] = src;
                dfs(nbr, par, adj, low, disc, critical, time);
                low[src] = min(low[src], low[nbr]);

                if (low[nbr] > disc[src])  critical.push_back({src, nbr});
            }

            else if (nbr != par[src]) //contains cycle
            {
                low[src] = min(low[src], disc[nbr]);
            }
        }
    }
};
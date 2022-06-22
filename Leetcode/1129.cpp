//Shortest Path BFS
//Time complexity - O(V+E)
//Space complexity - O(V+E)
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>&redEdges, vector<vector<int>>&blueEdges)
    {
        vector<vector<pair<int, int>>>adj(n); //node, {nbr,color}
        //red - 0, blue - 1
        for (auto v : redEdges)   adj[v[0]].push_back({v[1], 0});
        for (auto v : blueEdges)   adj[v[0]].push_back({v[1], 1});

        vector<vector<int>>cost(n, vector<int>(2, -1)); //{redCost, blueCost}

        queue<pair<int, int>>q; //{node,color}
        q.push({0, 0}); //Path can start from both the colors, i.e. pushing both 0 and 1
        q.push({0, 1});
        cost[0] = {0, 0};

        while (!q.empty())
        {
            auto p = q.front();
            int node = p.first, c1 = p.second;
            q.pop();

            for (auto [nbr, c2] : adj[node])
            {
                if (cost[nbr][c2] != -1 or c1 == c2)   continue;

                cost[nbr][c2] = 1 + cost[node][c1];
                q.push({nbr, c2});
            }
        }

        vector<int>res;
        for (auto v : cost)
        {
            int ans = -1;
            if (v[0] != -1 && v[1] != -1)    ans = min(v[0], v[1]); //can reach from both
            else if (v[0] == -1) ans = v[1];
            else if (v[1] == -1) ans = v[0];
            res.push_back(ans);
        }

        return res;
    }
};
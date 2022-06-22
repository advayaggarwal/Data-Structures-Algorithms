//DFS
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<int>adj[n];
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)    adj[manager[i]].push_back(i);
        }

        return dfs(headID, adj, informTime);
    }

    int dfs(int i, vector<int>adj[], vector<int>&informTime)
    {
        int ans = 0;
        for (int &nbr : adj[i])
        {
            ans = max(ans, dfs(nbr, adj, informTime));
        }

        return informTime[i] + ans;
    }
};

//BFS
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<int>adj[n];
        for (int i = 0; i < n; i++)  if (manager[i] != -1)    adj[manager[i]].push_back(i);

        int ans = 0;
        queue<pair<int, int>>q;
        q.push({headID, 0}); //{node, time}

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            int node = p.first;
            int timeTillNow = p.second + informTime[node];
            ans = max(ans, timeTillNow);

            for (int &nbr : adj[node])   q.push({nbr, timeTillNow});
        }

        return ans;
    }
};
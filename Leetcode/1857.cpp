class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<int>>cnt(n, vector<int>(26, 0)); //cnt[i][j] is the maximum count of jth color from the ancester nodes to node i.
        queue<int>q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                cnt[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0, nodes = 0;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            nodes++;

            int val = *max_element(cnt[x].begin(), cnt[x].end()); //max color value

            ans = max(ans, val);

            for (int nbr : adj[x])
            {
                for (int i = 0; i < 26; i++)
                {
                    cnt[nbr][i] = max(cnt[nbr][i], cnt[x][i] + (i == colors[nbr] - 'a'));
                }

                indegree[nbr]--;

                if (indegree[nbr] == 0)  q.push(nbr);

            }

        }

        return nodes == n ? ans : -1;
    }
};
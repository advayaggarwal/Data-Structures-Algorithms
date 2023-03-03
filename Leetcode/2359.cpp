//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int>dis1(n, INT_MAX), dis2(n, INT_MAX);
        bfs(node1, n, edges, dis1);
        bfs(node2, n, edges, dis2);

        int ans = INT_MAX, mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (dis1[i] == INT_MAX or dis2[i] == INT_MAX)    continue;

            int maxi = max(dis1[i], dis2[i]);
            if (mini > maxi)
            {
                mini = maxi;
                ans = i;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

    void bfs(int node, int n, vector<int>&edges, vector<int>&dis)
    {
        dis[node] = 0;
        queue<int>q;
        vector<bool>visited(n);
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            int nbr = edges[x];
            if (nbr == -1 or visited[nbr])   continue;
            else
            {
                visited[nbr] = true;
                dis[nbr] = dis[x] + 1;
                q.push(nbr);
            }
        }
    }
};
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int minJumps(vector<int>& arr)
    {
        int n = arr.size();
        if (n <= 1)  return 0;
        unordered_map<int, vector<int>>m;

        for (int i = 0; i < n; i++)
        {
            m[arr[i]].push_back(i);
        }

        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        visited[0] = true;
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int node = q.front();
                q.pop();

                if (node == n - 1) return level;

                if (node - 1 >= 0 && !visited[node - 1])
                {
                    q.push(node - 1);
                    visited[node - 1] = true;
                }

                if (node + 1 < n && !visited[node + 1])
                {
                    q.push(node + 1);
                    visited[node + 1] = true;
                }

                for (int nbr : m[arr[node]])
                {
                    if (!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }

                m.erase(arr[node]);
            }

            level++;
        }

        return -1;
    }
};
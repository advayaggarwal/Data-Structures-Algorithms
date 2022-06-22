//DFS, connected components
//Time complexity - O(E + VlogV)
//Space complexity - O(E + V)
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        int n = s.size();
        vector<int>adj[n];
        vector<bool>visited(n, false);

        for (vector<int>&edge : pairs)
        {
            int src = edge[0];
            int dest = edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }

        for (int v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                vector<char>characters;
                vector<int>indices;

                dfs(v, visited, adj, s, characters, indices);

                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());

                for (int i = 0; i < characters.size(); i++)
                {
                    s[indices[i]] = characters[i];
                }
            }
        }

        return s;
    }

    void dfs(int v, vector<bool>&visited, vector<int>adj[], string &s, vector<char>&characters, vector<int>&indices)
    {
        visited[v] = true;
        characters.push_back(s[v]);
        indices.push_back(v);

        for (int &nbr : adj[v])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited, adj, s, characters, indices);
            }
        }
    }
};
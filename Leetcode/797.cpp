//DAG - no need to take bool visited vector
//Time complexity - O(2^n), exponential
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>>ans;
        vector<int>path;
        dfs(n, 0, graph, ans, path);

        return ans;
    }

    void dfs(int n, int node, vector<vector<int>>& graph, vector<vector<int>>&ans, vector<int>&path)
    {
        path.push_back(node);

        if (node == n - 1)
        {
            ans.push_back(path);
        }

        else
        {
            for (int nbr : graph[node])
            {
                dfs(n, nbr, graph, ans, path);
            }
        }

        path.pop_back();
    }
};
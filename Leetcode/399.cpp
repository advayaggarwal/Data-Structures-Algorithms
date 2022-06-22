//Time complexity - O(m*n), where m is #equations and n is #queries
//Space complexity - O(V)
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, vector<pair<string, double>>>graph;

        for (int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double>res;
        for (int i = 0; i < queries.size(); i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];
            //have to find path from src to dest and mutiply all the weights
            double ans = -1.0;
            unordered_set<string>visited;
            if (graph.count(src) && graph.count(dest))   dfs(src, dest, graph, visited, ans, 1.0);
            res.push_back(ans);
        }

        return res;
    }

    void dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>&graph, unordered_set<string>&visited, double &ans, double temp)
    {
        visited.insert(src);
        if (src == dest)
        {
            ans = temp;
            return;
        }

        for (auto &v : graph[src])
        {
            string nbr = v.first;
            double cost = v.second;
            if (!visited.count(nbr))
            {
                dfs(nbr, dest, graph, visited, ans, temp * cost);
            }
        }
    }
};
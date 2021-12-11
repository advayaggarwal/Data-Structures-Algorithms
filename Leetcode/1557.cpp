//Have to take all the nodes which have indegree equal to 0, as we can't reach that node from any other node
//Time complexity - O(e), where e is #edges
//Space complexity - O(n)
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        vector<int>in(n, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            in[v]++;
        }

        vector<int>res;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)    res.push_back(i);
        }

        return res;
    }
};
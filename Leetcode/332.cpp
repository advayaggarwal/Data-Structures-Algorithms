//Time complexity - O(E*logE)
//Space complexity - O(V+E)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, multiset<string>>m;

        for (int i = 0; i < tickets.size(); i++)
        {
            string u = tickets[i][0];
            string v = tickets[i][1];
            m[u].insert(v);
        }

        vector<string>ans;

        dfs("JFK", m, ans);
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void dfs(string source, unordered_map<string, multiset<string>> &m, vector<string>&ans)
    {
        while (m[source].size() > 0)
        {
            auto it = m[source].begin();

            string nbr = *it;

            m[source].erase(it);

            dfs(nbr, m, ans);
        }

        ans.push_back(source);
    }
};
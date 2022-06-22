//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<vector<int>>res;
        vector<pair<int, int>>build;

        int n = buildings.size();
        for (int i = 0; i < n; i++)
        {
            build.push_back({buildings[i][0], -buildings[i][2]});
            build.push_back({buildings[i][1], buildings[i][2]});
        }

        sort(build.begin(), build.end(), [&](pair<int, int>&a, pair<int, int>&b) {
            if (a.first == b.first)  return a.second < b.second;
            return a.first < b.first;
        });

        multiset<int>height; //using it as max priority queue, thereby pushing heights as negative
        height.insert(0);
        int maxHeight = 0;

        for (int i = 0; i < build.size(); i++)
        {
            if (build[i].second < 0) height.insert(build[i].second);
            else
            {
                auto it = height.find(-build[i].second);
                if (it != height.end())  height.erase(it);
            }

            if (maxHeight != -(*height.begin()))
            {
                maxHeight = -(*height.begin());
                res.push_back({build[i].first, maxHeight});
            }
        }

        return res;
    }
};
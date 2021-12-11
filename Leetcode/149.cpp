//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        if (n <= 2)  return n;

        unordered_map<float, int>m;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            m.clear();
            for (int j = i + 1; j < n; j++)
            {
                float slope;
                if (points[j][0] - points[i][0] == 0)  slope = INT_MAX;
                else slope = ((points[j][1] - points[i][1]) * 1.0) / (points[j][0] - points[i][0]);
                m[slope]++;
                count = max(count, m[slope] + 1);
            }
        }

        return count;
    }
};
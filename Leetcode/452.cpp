//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int ans = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                ans++;
                end = points[i][1];
            }
        }

        return ans;
    }
};
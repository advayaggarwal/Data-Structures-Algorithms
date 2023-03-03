//Time complexity - O(n^4)
//Space complexity - O(n^2)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int n = img1.size();
        vector<pair<int, int>>ones1, ones2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        int ans = 0;
        map<pair<int, int>, int>m;

        for (auto [i1, j1] : ones1)
        {
            for (auto [i2, j2] : ones2)
            {
                m[ {i2 - i1, j2 - j1}]++;
                ans = max(ans, m[ {i2 - i1, j2 - j1}]);
            }
        }

        return ans;
    }
};
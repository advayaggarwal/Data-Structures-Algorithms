//Time complexity - O(m*logm + n*logn)
//Space complexity - O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        int mod = 1e9 + 7, m = horizontalCuts.size(), n = verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int height = max(horizontalCuts[0] - 0, h - horizontalCuts[m - 1]);
        int width = max(verticalCuts[0] - 0, w - verticalCuts[n - 1]);

        for (int i = 1; i < m; i++) height = max(height, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < n; i++)  width = max(width, verticalCuts[i] - verticalCuts[i - 1]);

        return (height * 1LL * width) % mod;
    }
};
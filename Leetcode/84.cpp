//Time complexity - O(3N)
//Time complexity - O(2N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        vector<int>nsrIndex = nsr(heights);
        vector<int>nslIndex = nsl(heights);

        int n = heights.size(), ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int area = heights[i] * (nsrIndex[i] - nslIndex[i] - 1);
            ans = max(ans, area);
        }

        return ans;
    }

    vector<int>nsr(vector<int>&heights)
    {
        stack<int>s;
        int n = heights.size();
        vector<int>nsrIndex;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if (!s.empty()) nsrIndex.push_back(s.top());
            else nsrIndex.push_back(n);

            s.push(i);
        }

        reverse(nsrIndex.begin(), nsrIndex.end());
        return nsrIndex;
    }

    vector<int>nsl(vector<int>&heights)
    {
        stack<int>s;
        int n = heights.size();
        vector<int>nslIndex;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if (!s.empty())  nslIndex.push_back(s.top());
            else nslIndex.push_back(-1);

            s.push(i);
        }

        return nslIndex;
    }
};
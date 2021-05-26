//Time complexity - O(3N)
//Time complexity - O(2N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>nsr_index = nsr(heights);
        vector<int>nsl_index = nsl(heights);

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            nsr_index[i] = nsr_index[i] - nsl_index[i] - 1;

            int area = nsr_index[i] * heights[i];
            ans = max(ans, area);

        }

        return ans;

    }


    vector<int>nsr(vector<int>& heights)
    {
        vector<int>v;
        stack<int>s;
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())   v.push_back(n);
            else if (heights[s.top()] < heights[i])   v.push_back(s.top());
            else
            {
                while (!s.empty() && heights[s.top()] >= heights[i])  s.pop();
                if (s.empty())   v.push_back(n);
                else v.push_back(s.top());
            }

            s.push(i);
        }

        reverse(v.begin(), v.end());
        return v;
    }

    vector<int>nsl(vector<int>& heights)
    {
        vector<int>v;
        stack<int>s;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            if (s.empty())   v.push_back(-1);
            else if (heights[s.top()] < heights[i])   v.push_back(s.top());
            else
            {
                while (!s.empty() && heights[s.top()] >= heights[i])  s.pop();
                if (s.empty())   v.push_back(-1);
                else v.push_back(s.top());
            }

            s.push(i);
        }
        return v;
    }


};
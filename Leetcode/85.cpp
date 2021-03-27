class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.size() == 0)    return 0;
        vector<vector<int>>m(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < (int)matrix.size(); i++)
        {
            for (int j = 0; j < (int)matrix[0].size(); j++)   m[i][j] = matrix[i][j] - '0';
        }
        int mx = mah(m[0]);

        for (int i = 1; i < (int)m.size(); i++)
        {
            for (int j = 0; j < (int)m[0].size(); j++)
            {
                if (m[i][j] == 1) m[i][j] += m[i - 1][j];
            }
            mx = max(mx, mah(m[i]));
        }

        return mx;
    }

    vector<int> nsr(vector<int>&arr, int n)
    {
        stack<pair<int, int>>s;
        vector<int>v;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.size() == 0) v.push_back(n);
            else if (s.top().first < arr[i] )    v.push_back(s.top().second);
            else
            {
                while (s.size() != 0 && s.top().first >= arr[i])   s.pop();
                if (s.size() == 0) v.push_back(n);
                else v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }

        reverse(v.begin(), v.end());
        return v;
    }

    vector<int> nsl(vector<int>&arr, int n)
    {
        stack<pair<int, int>>s; //{element,index}
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0) v.push_back(-1);
            else if (s.top().first < arr[i]) v.push_back(s.top().second);
            else
            {
                while (s.size() != 0 && s.top().first >= arr[i])   s.pop();
                if (s.size() == 0) v.push_back(-1);
                else v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        return v;
    }

    int mah(vector<int>& arr)
    {
        vector<int> right_index = nsr(arr, arr.size());
        vector<int> left_index = nsl(arr, arr.size());

        int max = INT_MIN;
        for (int i = 0; i < (int)arr.size(); i++)
        {
            if (max < ((right_index[i] - left_index[i] - 1)*arr[i])) max = (right_index[i] - left_index[i] - 1) * arr[i];
        }
        return max;
    }
};
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        vector<int>degree(n);

        for (auto &r : roads)
        {
            degree[r[0]]++;
            degree[r[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += degree[i] * 1LL *  (i + 1);
        }

        return ans;
    }
};
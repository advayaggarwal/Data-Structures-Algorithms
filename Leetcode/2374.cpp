//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int edgeScore(vector<int>& edges)
    {
        int n = edges.size();
        vector<long long int>s(n);

        for (int i = 0; i < n; i++)
        {
            s[edges[i]] += 1LL * i;
        }

        long long ans = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (sum < s[i])
            {
                sum = s[i];
                ans = i;
            }
        }

        return ans;
    }
};
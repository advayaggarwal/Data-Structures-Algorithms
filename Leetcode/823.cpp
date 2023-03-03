//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long>m;
        int n = arr.size(), mod = 1e9 + 7, ans = 0;
        for (int i = 0; i < n; i++)
        {
            long count = 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && m.count(arr[i] / arr[j]))
                {
                    count += m[arr[j]] * m[arr[i] / arr[j]];
                }
            }

            m[arr[i]] = count;
            ans = (ans + m[arr[i]]) % mod;
        }

        return ans;
    }
};
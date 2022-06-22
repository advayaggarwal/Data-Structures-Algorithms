//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int totalStrength(vector<int>& strength)
    {
        long long ans = 0;
        int n = strength.size();
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                sum = (sum + strength[j]) % mod;
                mini = min(mini, strength[j]);
                ans += (sum * mini) % mod;
                ans %= mod;
            }
        }

        return ans;
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
const int mod = 1e9 + 7;
class Solution {
public:
    int totalStrength(vector<int>& strength)
    {
        int n = strength.size();
        vector<long long>prefixSum(n + 1), prePrefixSum(n + 1);
        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] = (prefixSum[i - 1] + strength[i - 1]) % mod;
            prePrefixSum[i] = (prePrefixSum[i - 1] + prefixSum[i]) % mod;
        }

        long long ans = 0;
        vector<int>prev(n), next(n);
        stack<int>st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && strength[st.top()] > strength[i])  st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int>(); //clearing the stack

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && strength[st.top()] >= strength[i])  st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int j = 1; j <= n; j++)
        {
            int prv = prev[j - 1] + 1, nxt = next[j - 1] + 1;

            long long minus = (prePrefixSum[j - 1] - (prv == 0 ? 0 : prePrefixSum[prv - 1]) + mod) % mod;
            long long plus = (prePrefixSum[nxt - 1] - prePrefixSum[j - 1] + mod) % mod;

            long long before = j - prv;
            long long after = nxt - j;
            long long total = ((plus * before) % mod - (minus * after) % mod  + mod) % mod;

            ans = (ans + (total * strength[j - 1]) % mod) % mod;
        }

        return ans;
    }
};
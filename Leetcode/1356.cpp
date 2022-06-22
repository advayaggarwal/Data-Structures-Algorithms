class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        unordered_map<int, int>m;
        for (int n : arr) countSetBits(n, m);
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (m[a] == m[b])    return a < b;
            return m[a] < m[b];
        });

        return arr;
    }

    void countSetBits(int n, unordered_map<int, int>&m)
    {
        int temp = n;
        int ans = 0;
        while (temp)
        {
            ans++;
            temp &= (temp - 1);
        }

        m[n] = ans;
    }
};
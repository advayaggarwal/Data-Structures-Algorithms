//Using Sorting
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int, int>m;
        vector<int>freq;
        int n = arr.size();
        for (int i = 0; i < n; i++)  m[arr[i]]++;
        for (auto p : m) freq.push_back(p.second);

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0, sz = 0;
        for (int i = 0; i < freq.size() && sz < (n + 1) / 2; i++)
        {
            ans++;
            sz += freq[i];
        }

        return ans;
    }
};

//Using Count Sort
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int, int>m;
        int n = arr.size();
        vector<int>counting(n + 1);
        for (int i = 0; i < n; i++)  m[arr[i]]++;
        for (auto p : m) counting[p.second]++;

        int ans = 0, sz = 0, freq = n;
        while (sz < (n + 1) / 2)
        {
            ans++;
            while (counting[freq] == 0)  freq--;
            sz += freq;
            counting[freq]--;
        }

        return ans;
    }
};
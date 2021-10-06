class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>m;

        int n = nums.size();
        for (auto e : nums)    m[e]++;

        vector<int>res;

        vector<pair<int, int>>v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], m[nums[i]]});
        }

        sort(v.begin(), v.end(), mycomp);

        for (int i = 0; i < n; i++)  res.push_back(v[i].first);

        return res;
    }

    static bool mycomp(pair<int, int>a, pair<int, int>b)
    {
        if (a.second < b.second) return true;

        else if (a.second == b.second)   return a.first > b.first;

        return false;
    }
};

//Using lambda function
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>m;

        for (auto e : nums)    m[e]++;

        sort(nums.begin(), nums.end(), [&](int a, int b) { //[&] : capture all external variable by reference
            if (m[a] == m[b])  return a > b;

            return m[a] < m[b];
        });

        return nums;
    }

};
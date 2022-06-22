#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> nums)
{
    int n = nums.size();
    unordered_map<int, int>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = nums[i] & nums[j];
            m[val]++;
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto p : m)
        {
            if ((p.first & nums[i]) == 0)  count += p.second;
        }
    }

    return count;
}
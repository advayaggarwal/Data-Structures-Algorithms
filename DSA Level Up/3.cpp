#include<bits/stdc++.h>
using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, m = a.size(), n = b.size();
    int difference = INT_MAX, min_difference = INT_MAX;

    pair<int, int>res;
    while (i < m && j < n)
    {
        difference = abs(a[i] - b[j]);
        if (difference < min_difference)
        {
            min_difference = difference;
            res = {a[i], b[j]};
        }

        if (a[i] < b[j]) i++;
        else j++;
    }

    return res;
}
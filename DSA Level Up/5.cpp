#include<bits/stdc++.h>
using namespace std;


int countActivites(vector<pair<int, int> > activities)
{
    sort(activities.begin(), activities.end(), [&](pair<int, int>&a, pair<int, int>&b) {
        return a.second < b.second;
    });

    int count = 1;
    int endTime = activities[0].second;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].first >= endTime)
        {
            count++;
            endTime = activities[i].second;
        }
    }

    return count;
}
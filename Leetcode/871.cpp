class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        if (startFuel >= target) return 0;
        map<pair<int, int>, int>dp;
        int ans = helper(0, target, startFuel, stations, dp);
        return ans > 500 ? -1 : ans;
    }

    int helper(int i, int target, int fuel, vector<vector<int>>& stations, map<pair<int, int>, int>&dp)
    {
        if (fuel >= target)   return 0;
        if (i == stations.size() or fuel < stations[i][0])    return 501;
        if (dp.count({i, fuel}))   return dp[ {i, fuel}];

        int take = 1 + helper(i + 1, target, fuel + stations[i][1], stations, dp);
        int notTake = helper(i + 1, target, fuel, stations, dp);

        return dp[ {i, fuel}] = min(take, notTake);
    }
};

//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        priority_queue<int>pq;
        int ans = 0, i = 0, fuel = startFuel;
        while (fuel < target) //not yet reached
        {
            while (i < stations.size() && fuel >= stations[i][0]) //can reach till here with fuel 'fuel'
            {
                pq.push(stations[i][1]);
                i++;
            }

            if (pq.empty())  return -1;

            fuel += pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int n = trips.size();
        vector<int>occupancy(1001);
        for (int i = 0; i < n; i++)
        {
            occupancy[trips[i][1]] += trips[i][0];
            occupancy[trips[i][2]] -= trips[i][0];
        }

        int currCapacity = 0;
        for (int i = 0; i <= 1000; i++)
        {
            currCapacity += occupancy[i];
            if (currCapacity > capacity)    return false;
        }

        return true;
    }
};
//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size(), count = 0;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (intervals[i][1] > intervals[i + 1][0])
            {
                count++;
                int s = max(intervals[i][0], intervals[i + 1][0]);
                int e = min(intervals[i][1], intervals[i + 1][1]);
                intervals[i + 1][0] = s;
                intervals[i + 1][1] = e;
            }
        }

        return count;
    }
};
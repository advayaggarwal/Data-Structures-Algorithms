//We will use ladders to take largest jumps
//Time complexity - O(n*logl), l is #ladders
//Space complexity - O(l)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        int n = heights.size(), i, bricksRequired = 0;
        priority_queue<int, vector<int>, greater<int>>pq; //min heap for maintaing largest l jumps, where l is #ladders
        for (i = 0; i < n - 1; i++)
        {
            if (heights[i + 1] > heights[i])
            {
                pq.push(heights[i + 1] - heights[i]);
                if (pq.size() > ladders)
                {
                    bricksRequired += pq.top(); //smallest jump, will use bricks for that
                    pq.pop();
                }

                if (bricksRequired > bricks) break;
            }
        }

        return i;
    }
};
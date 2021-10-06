//Time complexity - O(NlogK)

#define pii pair<int,int>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, pii>>maxHeap; //{distance, {x,y}}

        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            maxHeap.push({x * x + y * y, {x, y}});

            if (maxHeap.size() > k)  maxHeap.pop();
        }

        vector<vector<int>>res(k);

        int idx = 0;
        while (!maxHeap.empty())
        {
            pii point = maxHeap.top().second;
            maxHeap.pop();

            res[idx].push_back(point.first);
            res[idx].push_back(point.second);
            idx++;
        }
        return res;
    }
};
//Sorting
//Time complexity - O(nlogn)
//Space complexity - O(1)
#define pii pair<int,int>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<pair<int, pii>>v;
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int dis = x * x + y * y;

            v.push_back({dis, {x, y}});
        }

        sort(v.begin(), v.end());
        vector<vector<int>>res;
        for (int i = 0; i < k; i++)
        {
            pii p = v[i].second;
            res.push_back({p.first, p.second});
        }

        return res;
    }
};

//Max Heap
//Time complexity - O(NlogK)
//Space complexity - O(K)
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

            maxHeap.push({x * x + y * y, {x, y}}); //no need of pushing sqroot distance

            if (maxHeap.size() > k)  maxHeap.pop();
        }

        vector<vector<int>>res;

        while (!maxHeap.empty())
        {
            pii point = maxHeap.top().second;
            maxHeap.pop();

            res.push_back({point.first, point.second});
        }
        return res;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        int n = stones.size();

        priority_queue<int>q;
        for (int i = 0; i < n; i++)  q.push(stones[i]);

        while (q.size() > 1)
        {
            int f = q.top();
            q.pop();
            int s = q.top();
            q.pop();

            if (f != s)
            {
                q.push(f - s);
            }
        }

        return q.size() == 0 ? 0 : q.top();

    }
};
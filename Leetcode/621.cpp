class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)    return tasks.size();

        unordered_map<char, int>m;
        for (int i = 0; i < (int)tasks.size(); i++)  m[tasks[i]]++;


        priority_queue<int, vector<int>> maxHeap;

        for (auto ele : m) maxHeap.push(ele.second);
        int ans = 0;
        while (!maxHeap.empty())
        {
            vector<int>temp;
            for (int i = 0; i <= n; i++)
            {
                if (!maxHeap.empty())
                {
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }


            for (int ele : temp)
            {
                if (--ele > 0)   maxHeap.push(ele);
            }

            ans += maxHeap.empty() ? temp.size() : n + 1;
        }

        return ans;
    }
};
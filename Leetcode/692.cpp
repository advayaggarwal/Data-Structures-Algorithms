//Time complexity - O(nlogn + klogn)
//Space complexity - O(n)
class comp {
public:
    bool operator ()(pair<int, string>&a, pair<int, string>&b)
    {
        if (a.first == b.first)  return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int>m;
        for (string s : words)   m[s]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp>maxHeap;
        for (auto p : m)    maxHeap.push({p.second, p.first});
        vector<string>ans;

        while (k-- && !maxHeap.empty())
        {
            auto p = maxHeap.top();
            maxHeap.pop();
            ans.push_back(p.second);
        }

        return ans;
    }
};


//Time complexity - O(nlogk)
//Space complexity - O(n)
class comp {
public:
    bool operator ()(pair<int, string>&a, pair<int, string>&b)
    {
        if (a.first == b.first)  return a.second < b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int>m;
        for (string s : words)   m[s]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp>minHeap;
        for (auto p : m)
        {
            minHeap.push({p.second, p.first});
            if (minHeap.size() > k)  minHeap.pop();
        }

        vector<string>ans;

        while (k--)
        {
            auto p = minHeap.top();
            minHeap.pop();
            ans.push_back(p.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
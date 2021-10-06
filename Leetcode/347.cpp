//Using Max Heap
//Time complexity - O(K*log(N))
class Solution {
public:

  struct my_comp
  {
    bool operator() (pair<int, int>&a, pair<int, int>&b)
    {
      return a.second < b.second;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int>m;
    int n = nums.size();
    for (int i = 0; i < n; i++)  m[nums[i]]++;
    vector<int>res;

    priority_queue<pair<int, int>, vector<pair<int, int>>, my_comp> heap;

    for (auto ele : m)
    {
      heap.push({ele.first, ele.second});
    }

    for (int i = 0; i < k; i++) //O(K*log(N))
    {
      int ans = heap.top().first;
      heap.pop();
      res.push_back(ans);
    }
    return res;
  }


};


//Using Min Heap
//Time complexity - O(N*logK)
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int>m;
    int n = nums.size();
    for (int i = 0; i < n; i++)  m[nums[i]]++;
    vector<int>res;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for (auto ele : m) //O(N*logK)
    {
      heap.push({ele.second, ele.first});
      if (heap.size() > k)   heap.pop();
    }

    while (heap.size() != 0) //O(K*logK)
    {
      int ans = heap.top().second;
      heap.pop();
      res.push_back(ans);
    }
    return res;
  }
};


#define pii pair<int,int>
class Solution {
public:
  vector<int> topKFrequent(vector<int>& v, int k) {
    int n = v.size();

    vector<int>res;
    unordered_map<int, int>m; //{element, freq}

    for (int i = 0; i < n; i++) m[v[i]]++;

    priority_queue<pii, vector<pii>, greater<pii>>minHeap;

    for (auto p : m)
    {
      minHeap.push({p.second, p.first});//because sorting is done on the basis of first,
      //otherwise we had to make a custom comparator

      if (minHeap.size() > k) minHeap.pop();
    }

    //Now Min Heap contains top k frequent elements

    while (!minHeap.empty())
    {
      res.push_back(minHeap.top().second);
      minHeap.pop();
    }

    return res;
  }
};



//Bucket Sort
//Time complexity - O(N)
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int>m;
    int n = nums.size();
    for (int i = 0; i < n; i++)  m[nums[i]]++;
    vector<int>res;

    vector<vector<int>>bucket(n + 1);

    for (auto e : m)
    {
      bucket[e.second].push_back(e.first);
    }

    for (int i = n; i > 0 && res.size() < k; i--)
    {
      if (bucket[i].size() > 0)
      {
        for (int j = 0; j < bucket[i].size(); j++)   res.push_back(bucket[i][j]);
      }
    }

    return res;
  }
};
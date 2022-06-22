//Using Max Heap - TLE
//Time complexity - O(nlogn)
//Space complexity - O(n)
class KthLargest {
public:
    priority_queue<int>pq;
    int k1;
    KthLargest(int k, vector<int>& nums)
    {
        for (int &num : nums)    pq.push(num);
        k1 = k;
    }

    int add(int val)
    {
        pq.push(val);
        vector<int>temp;
        int count = k1 - 1;
        while (count--)
        {
            temp.push_back(pq.top());
            pq.pop();
        }

        int ans = pq.top();
        for (int &v : temp)  pq.push(v);

        return ans;
    }
};

//Using Min Heap
//Time complexity - O(nlogk)
//Space complexity - O(k)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int k1;
    KthLargest(int k, vector<int>& nums)
    {
        for (int &num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)  minHeap.pop();
        }

        k1 = k;
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k1)  minHeap.pop();

        return minHeap.top();
    }
};
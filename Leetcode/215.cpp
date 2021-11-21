//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};


//Time complexity - O(n), Worst case - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { //average O(n)
        int h = nums.size() - 1;
        int l = 0;
        k = nums.size() - k; //for 0 based indexing and treating ques as (nums.size()-k)th smallest element
        return quickselect(nums, l, h, k);

    }

    int quickselect(vector<int>&nums, int l, int h, int k)
    {
        if (l <= h)
        {
            int index = partition(nums, l, h);
            if (index == k)    return nums[index];
            else if (index > k) return quickselect(nums, l, index - 1, k);
            else return quickselect(nums, index + 1, h, k);
        }

        return -1;
    }

    int partition(vector<int>&nums, int l, int h)
    {
        int pivot = nums[h];
        int i = l - 1;
        for (int j = l; j < h; j++)
        {
            if (nums[j] <= pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[h]);
        return i + 1; //index of pivot
    }
};

//Using Max Heap
//Time complexity - O(n + klogn)
//Space complexity - O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>heap;
        int n = nums.size();
        for (int i = 0; i < n; i++) //O(n)
        {
            heap.push(nums[i]);
        }

        int ans;

        while (k--) //O(klogn)
        {
            ans = heap.top();
            heap.pop();
        }

        return ans;
    }
};

//Using Min Heap
//Time complexity - O(k + nlogk)
//Space complexity - O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>>heap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k)  heap.push(nums[i]);

            else
            {
                heap.push(nums[i]);
                heap.pop();
            }
        }

        return heap.top();
    }
};
//Time complexity - O(nlogn + klogk)
//Space complexity- O(n)
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {

		vector<pair<int, int>>distance; //{distance, element}

		for (int i = 0; i < arr.size(); i++)
		{
			distance.push_back({abs(arr[i] - x), arr[i]});
		}

		sort(distance.begin(), distance.end());

		vector<int>res;

		for (int i = 0; i < k; i++)
		{
			res.push_back(distance[i].second);
		}

		sort(res.begin(), res.end());
		return res;

	}
};


//Using Max Heap
//Time complexity - O(nlogk + klogk)
//Space complexity- O(k)
#define pii pair<int,int>

class Solution {
public:
	vector<int> findClosestElements(vector<int>& v, int k, int x)
	{
		priority_queue<pii> maxHeap; //{distance, element}

		for (int i = 0; i < v.size(); i++)
		{
			maxHeap.push({abs(x - v[i]), v[i]});

			if (i >= k)
			{
				maxHeap.pop();
			}
		}

		vector<int>res;
		while (!maxHeap.empty())
		{
			res.push_back(maxHeap.top().second);
			maxHeap.pop();
		}
		sort(res.begin(), res.end());

		return res;
	}
};


//Binary Search
//Time complexity - O(logn + k + klogk)
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x)
	{
		int n = arr.size();
		vector<int>res;

		int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

		index--;
		int l = index, r = index + 1;

		int count = 0;

		while (count < k)
		{
			if (l >= 0 and r < n)
			{
				if (x - arr[l] <= arr[r] - x)  res.push_back(arr[l--]);
				else res.push_back(arr[r++]);
			}

			else if (l >= 0)   res.push_back(arr[l--]);

			else    res.push_back(arr[r++]);

			count++;
		}

		sort(res.begin(), res.end());
		return res;
	}
};
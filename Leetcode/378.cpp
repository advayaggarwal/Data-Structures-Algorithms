//Time complexity - O(n*n*log(n*n)), where n is the size of matrix
//Space complexity - O(n*n), as we are using vector
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        vector<int>v;

        for (auto m : matrix)
        {
            for (int e : m)    v.push_back(e);
        }

        sort(v.begin(), v.end());

        return v[k - 1];
    }
};



//Binary Search
//Time complexity - O(n*log(max-min)), where n is the size of matrix and max-min is the range of elements
//Space complexity - O(1)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int hi = matrix[n - 1][n - 1];
        int ans = -1;
        while (low <= hi)
        {
            int mid = low + (hi - low) / 2;

            if (countLessOrEqual(mid, matrix, n) < k)  low = mid + 1;
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }

        return ans;
    }

    int countLessOrEqual(int mid, vector<vector<int>>&matrix, int n)
    {
        int i = 0, j = n - 1, count = 0;
        while (i < n and j >= 0)
        {
            if (matrix[i][j] <= mid)
            {
                count += (j + 1);
                i++;
            }

            else
            {
                j--;
            }
        }

        return count;
    }
};


//Min heap
//Time complexity - O(klogn), n is the size of matrix
//Space complexity - O(n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = matrix.size();

        for (int i = 0; i < n; i++)  pq.push({matrix[i][0], {i, 0}});

        int ans;

        while (k--) //O(klogn)
        {
            int e = pq.top().first;

            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();
            ans = e;

            if (y < n - 1) pq.push({matrix[x][y + 1], {x, y + 1}});

        }

        return ans;
    }
};
//Binary Search on answer
//Time complexity - O(n*log(INT_MAX))
//Space complexity - O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = 0, high = INT_MAX, ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (possible(mid, weights, days))
            {
                ans = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return ans;
    }

    bool possible(int capacity, vector<int>&weights, int days)
    {
        int w = 0, d = 1;
        for (int i = 0; i < weights.size(); i++)
        {
            if (capacity < weights[i])   return false;
            w += weights[i];
            if (w > capacity)
            {
                w = weights[i];
                d++;
            }
        }

        return d <= days;
    }
};

//Minor improvements like low will be max_element and high will be sum of all elements
//Time complexity - O(n*log(500*n)), given that max element is 500, so total sum will be 500*n in worst case
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0), ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (possible(mid, weights, days))
            {
                ans = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return ans;
    }

    bool possible(int capacity, vector<int>&weights, int days)
    {
        int w = 0, d = 1;
        for (int i = 0; i < weights.size(); i++)
        {
            w += weights[i];
            if (w > capacity)
            {
                w = weights[i];
                d++;
            }
        }

        return d <= days;
    }
};
//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        return w + helper(0, k, w, profits, capital);
    }

    int helper(int i, int k, int w, vector<int>&profits, vector<int>&capital)
    {
        if (i == profits.size() or k == 0)   return 0;

        int notTake = helper(i + 1, k, w, profits, capital);
        int take = 0;
        if (w >= capital[i]) take = profits[i] + helper(i + 1, k - 1, w + profits[i], profits, capital);

        return max(take, notTake);
    }
};

//Greedy
//Time complexity - O(k + nlogn)
//Space complexity - O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        int n = profits.size();
        vector<pair<int, int>>temp;
        for (int i = 0; i < n; i++)  temp.push_back({capital[i], profits[i]});
        sort(temp.begin(), temp.end());

        priority_queue<int>profit;
        int j = 0;
        for (int i = 0; i < k; i++)
        {
            while (j < n && temp[j].first <= w)  profit.push(temp[j++].second);
            if (profit.empty())  break;

            w += profit.top();
            profit.pop();
        }

        return w;
    }
};
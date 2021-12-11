//Time complexity - O(orders*log(n)), where n is the size of inventory - TLE
//Space complexity - O(n)
class Solution {
public:
    const int mod = 1e9 + 7;
    int maxProfit(vector<int>& inventory, int orders)
    {
        priority_queue<int>maxHeap(inventory.begin(), inventory.end());

        int ans = 0;
        while (orders--)
        {
            int temp = maxHeap.top();
            ans = (ans + temp) % mod;
            maxHeap.pop();

            if (temp - 1 > 0)  maxHeap.push(temp - 1);
        }

        return ans;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;
    int maxProfit(vector<int>& v, int orders)
    {
        long long int ans = 0;
        int n = v.size();
        sort(v.begin(), v.end());

        for (int i = n - 1; i >= 0; i--)
        {
            long long int diff = v[i] - (i > 0 ? v[i - 1] : 0);

            long long int count = min(1LL * orders, (n - i) * diff); //the number of orders we can take
            long long int r = v[i];
            long long int l = r - count / (n - i);

            ans += ((r * (r + 1)) / 2 - (l * (l + 1)) / 2) * (n - i);
            ans %= mod;
            ans += l * (count % (n - i));
            ans %= mod;

            orders -= count;
        }


        return ans;
    }
};
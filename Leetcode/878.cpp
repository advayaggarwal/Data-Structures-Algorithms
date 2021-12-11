//Time complexity - O(nlogn) -> TLE
//Space complexity - O(n)
class Solution {
public:
    const int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b)
    {
        if (a > b)   swap(a, b);

        set<long long int>res;

        for (long long int i = 1; i <= n; i++)
        {
            res.insert(((i % mod) * (a % mod)) % mod);
            res.insert(((i % mod) * (b % mod)) % mod);
        }

        int ans, count = 0;
        auto it = res.begin();
        for (; it != res.end() && count < n; it++)   count++;

        it--;
        return *it;
    }
};

//Binary Search
//Time complexity - O(logn)
//Space complexity - O(1)
#define ll long long int
class Solution {
public:
    const int mod = 1e9 + 7;

    ll lcm(ll a, ll b)
    {
        return (a * b) / __gcd(a, b);
    }

    ll getPosition(ll x, ll a, ll b)
    {
        return x / a + x / b - x / lcm(a, b);
    }

    int nthMagicalNumber(int n, int a, int b)
    {
        ll low = 1, hi = 1e18;

        while (low < hi)
        {
            ll mid = low + (hi - low) / 2;
            ll position = getPosition(mid, a, b); //position of mid in the magical number sequence

            if (position < n)   low = mid + 1;
            else hi = mid;
        }

        return low % mod;
    }
};
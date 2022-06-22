//Time complexity - O(n*sqrt(n))
//Space complexity - O(n)
//Idea - It can be shown that if (n1 * n2) % k == 0, then (gcd(n1, k) * gcd(n2, k)) % k == 0.
class Solution {
public:
    long long countPairs(vector<int>& nums, int k)
    {
        unordered_map<int, int>m;
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int gcd = __gcd(nums[i], k);
            int want = k / gcd;
            for (auto p : m)
            {
                if (p.first % want == 0)   ans += p.second;
            }
            m[gcd]++;
        }

        return ans;
    }
};
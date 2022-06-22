//Time complexity - O(m*logm + n*logm)
//Space complexity - O(1)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int>res(n);

        for (int i = 0; i < n; i++)
        {
            int lo = 0, hi = m - 1, ans = m;
            //finding the smallest index in potions which satisfy the given condition
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (spells[i] * 1LL * potions[mid] >= success) //mid could be a potential ans
                {
                    ans = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }

            res[i] = m - ans;
        }

        return res;
    }
};

//Same approach by using STL
//Time complexity - O(m*logm + n*logm)
//Space complexity - O(1)
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> res;
    for (int a : spells) {
        long need = (success + a - 1) / a;
        auto it = lower_bound(potions.begin(), potions.end(), need);
        res.push_back(potions.end() - it);
    }
    return res;
}
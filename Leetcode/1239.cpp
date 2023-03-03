/*
Time complexity - O(2 ^ n * (26 + n)), where n <= 16 is length of arr array.
There is 2 ^ n bitmask states.
There are up to 26 distinct characters we can form.
Space complexity - O(26)
*/
class Solution { // 36 ms, faster than 66.95%
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), allMask = 1 << n, ans = 0;
        for (int mask = 0; mask < allMask; ++mask) {
            int strSize = 0;
            int seen = 0; // the mask to check duplicate chars when forming string
            bool isValid = true;
            for (int i = 0; i < n; ++i) {
                if (((mask >> i) & 1) == 0) continue;
                for (char c : arr[i]) {
                    int j = c - 'a';
                    if ((seen >> j) & 1) { // If c is already existed then it's invalid subsequence.
                        isValid = false;
                        break;
                    }
                    seen = seen | (1 << j); // mark as character `c` is already seen
                    strSize += 1;
                }
                if (!isValid) break; //  prune when there is a duplicate
            }
            if (isValid && strSize > ans) ans = strSize;
        }

        return ans;
    }
};

class Solution {
public:
    int maxLength(vector<string>& A)
    {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto& s : A) {
            bitset<26> a;
            for (char c : s)
                a.set(c - 'a'); //sets bit as 1 at index c-'a'
            int n = a.count(); //counts the number of set bits
            if (n < s.size()) continue;

            for (int i = dp.size() - 1; i >= 0; --i) {
                bitset c = dp[i];
                if ((c & a).any()) continue; //.any() returns true if any bit is set
                dp.push_back(c | a);
                res = max(res, (int)c.count() + n);
            }
        }
        return res;
    }
};
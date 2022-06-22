//Brute Force
//Time complexity - O(n*k)
//Space complexity - O(n*k)
class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        int n = s.size();
        unordered_set<string>codes;

        for (int i = 0; i <= n - k; i++)
        {
            string sub = s.substr(i, k);
            codes.insert(sub);
        }

        return codes.size() == 1 << k;
    }
};

/*

Rolling Hash

https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/2092553/Explaining-the-Rolling-Hash-Method-or-Guide
The main inefficiency with our previous approach is that at each iteration, we're creating a substring of length k which takes O(k) time.
However, as you're about to realise, there's no need to do this! The main thing to notice here is that each
substring is quite simply the previous substring but shifted to the righ by 1. Therefore, we can just use the
previous substring to create our current one. This can save heaps of time especially for larger k values where
we still have a lot of the same characters in the middle.

*/
//Time complexity - O(n)
//Space complexity - O(n*k)
class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        int n = s.size();
        unordered_set<int>codes;
        int allOnes = (1 << k) - 1; //all 1s of size k 111..k
        int subString = 0;

        for (int i = 0; i < n; i++)
        {
            subString = ((subString << 1) & allOnes) | (s[i] - '0');
            if (i >= k - 1)    codes.insert(subString);
        }

        return codes.size() == 1 << k;
    }
};
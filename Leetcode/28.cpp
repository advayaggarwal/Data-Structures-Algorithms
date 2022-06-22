//Brute Force
//Time complexity - O(m*n)
//Space complexity - O(1)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")    return 0;

        int ans = -1;

        int m = haystack.size(), n = needle.size();
        int i = 0;
        while (i <= m - n)
        {
            if (haystack[i] == needle[0])
            {
                if (haystack.substr(i, n) == needle) return i;
            }
            i++;
        }

        return ans;
    }
};

//Brute Force with easier implementation
//Time complexity - O(m*n)
//Space complexity - O(1)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")    return 0;

        int m = haystack.size(), n = needle.size();

        for (int i = 0; i <= m - n; i++)
        {
            int j = 0;
            for (; j < n; j++)
            {
                if (needle[j] != haystack[i + j])  break;
            }

            if (j == n)    return i;
        }

        return -1;
    }
};

//KMP
//Time complexity - O(m+n)
//Space complexity - O(n)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (!n)  return 0;
        vector<int>lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m; )
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }

            if (j == n) return i - j;

            if (i < m && haystack[i] != needle[j])
            {
                if (j)   j = lps[j - 1];
                else i++;
            }
        }

        return -1;
    }

    vector<int>kmpProcess(string &needle)
    {
        int n = needle.size();
        vector<int>lps(n);
        int len = 0, i = 1;
        while (i < n)
        {
            if (needle[i] == needle[len])
            {
                lps[i++] = ++len;
            }

            else if (len)   len = lps[len - 1];
            else lps[i++] = 0;
        }
        return lps;
    }
};

//KMP with shorter code
//Time complexity - O(m+n)
//Space complexity - O(n)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (!n)  return 0;
        string s = needle + "#" + haystack;
        vector<int>lps = kmpProcess(s);
        for (int i = 0; i < s.size(); i++)
        {
            if (lps[i] == n) return i - 2 * n;
        }

        return -1;
    }
    vector<int>kmpProcess(string &needle)
    {
        int n = needle.size();
        vector<int>lps(n);
        int len = 0, i = 1;
        while (i < n)
        {
            if (needle[i] == needle[len])
            {
                lps[i++] = ++len;
            }

            else if (len)   len = lps[len - 1];
            else lps[i++] = 0;
        }
        return lps;
    }
};
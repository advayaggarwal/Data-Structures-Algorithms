//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool validPalindrome(string s)
    {
        int n = s.size(), i = 0, j = n - 1;
        int count = 0;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return isPalindrome(s, i + 1, j) or isPalindrome(s, i, j - 1);
            }

            i++;
            j--;
        }

        return true;
    }

    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])    return false;
        }
        return true;
    }
};
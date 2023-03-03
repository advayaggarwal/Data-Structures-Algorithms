//Brute force, trying to change every character and then taking minimum
//Time complexity - O(n*n*26)
//Space complexity - O(1)
class Solution {
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (palindrome[i] != ch)
                {
                    string s = palindrome;
                    s[i] = ch;
                    if (!isPalindrome(s))
                    {
                        if (ans == "")    ans = s;
                        else ans = min(ans, s);
                    }
                }
            }
        }

        return ans;
    }

    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            if (s[i++] != s[j--])    return false;
        }

        return true;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.size() == 1)  return "";
        int n = palindrome.size();

        for (int i = 0; i < n / 2; i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[n - 1] = 'b';

        return palindrome;
    }
};
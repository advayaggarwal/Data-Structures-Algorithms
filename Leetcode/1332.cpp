//Idea - String only contains a & b, and if it is palindrome we can remove it in 1 step, but if it's not
//a palindrome, then we need only 2 steps, in 1st step we'll remove all a's and in 2nd step we'll remove all b's
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int removePalindromeSub(string s)
    {
        if (s.size() == 0)   return 0;
        if (palindrome(s))   return 1;
        return 2;
    }

    bool palindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)   if (s[i++] != s[j--])    return false;
        return true;
    }
};
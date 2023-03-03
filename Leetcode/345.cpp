//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            while (i < s.size() && !isVowel(s[i])) i++;
            while (j >= 0 && !isVowel(s[j]))  j--;
            if (i < j)  swap(s[i++], s[j--]); //both are vowels
        }

        return s;
    }

    bool isVowel(char c)
    {
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
            return true;

        return false;
    }
};
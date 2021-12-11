//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        s = modifyString(s);
        t = modifyString(t);

        return s == t;
    }

    string modifyString(string s)
    {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '#') res += s[i];

            else
            {
                if (res.size() > 0)  res.pop_back();
            }
        }

        return res;
    }
};

/*
Can you do it in O(N) time and O(1) space?
I believe you have one difficulty here:
When we meet a char, we are not sure if it will be still there or be deleted.

However, we can do a back string compare (just like the title of problem).
If we do it backward, we meet a char and we can be sure this char won't be deleted.
If we meet a '#', it tell us we need to skip next lowercase char.

The idea is that, read next letter from end to start.
If we meet #, we increase the number we need to step back, until back = 0
*/

//Time complexity - O(n)
//Space complexity - O(1)
bool backspaceCompare(string S, string T)
{
    int i = S.length() - 1, j = T.length() - 1, back;
    while (true)
    {
        back = 0;
        while (i >= 0 && (back > 0 || S[i] == '#'))
        {
            back += S[i] == '#' ? 1 : -1;
            i--;
        }

        back = 0;

        while (j >= 0 && (back > 0 || T[j] == '#'))
        {
            back += T[j] == '#' ? 1 : -1;
            j--;
        }

        if (i >= 0 && j >= 0 && S[i] == T[j])
        {
            i--;
            j--;
        }
        else    break;

    }

    return i == -1 && j == -1;
}
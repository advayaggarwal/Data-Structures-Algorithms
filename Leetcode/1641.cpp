//Recursion + Backtracking
//Time complexity - Exponential
//Space complexity - O(n)
class Solution {
public:
    int countVowelStrings(int n)
    {
        vector<char>vowel = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        string vowelString;
        helper(0, n, vowel, vowelString, count);
        return count;
    }

    void helper(int i, int n, vector<char>&vowel, string &vowelString, int &count)
    {
        if (vowelString.size() == n)
        {
            count++;
            return;
        }

        for (int j = i; j < 5; j++)
        {
            vowelString += vowel[j];
            helper(j, n, vowel, vowelString, count);
            vowelString.pop_back();
        }
    }
};

/*
          a  e  i  o  u
    n=1   1  1  1  1  1  /a, e, i, o, u
    n=2   5  4  3  2  1  /a-> aa,ae,ai,ao,au | e-> ee,ei,eo,eu | i-> ii,io,iu | o-> oo,ou | u-> uu
    n=3   15 10 6  3  1

If we observe from last there will be only 1 element which will start with u.
Every other element will have the count of previous count + next element count. As example
in n=2, i will be previous i(1) + count of next element, o(2) → 3
in n=3, e will be previous e(4) + count of next element, i(6) → 10
*/

//Using DP
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int countVowelStrings(int n)
    {
        vector<int>dp(5, 1);

        while (--n)
        {
            for (int i = 3; i >= 0; i--)
            {
                dp[i] += dp[i + 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < 5; i++)  ans += dp[i];

        return ans;
    }
};

//DP with space optimisation
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int countVowelStrings(int n)
    {
        int a = 1, e = 1, i = 1, o = 1, u = 1;

        while (--n)
        {
            o += u;
            i += o;
            e += i;
            a += e;
        }

        return a + e + i + o + u;
    }
};
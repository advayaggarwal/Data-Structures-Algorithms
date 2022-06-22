//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string getSmallestString(int n, int k)
    {
        string res;

        for (int i = n; i > 0; i--)
        {
            int val = k - (i - 1);
            if (val >= 26)
            {
                res += 'z';
                k -= 26;
            }
            else
            {
                res += ('a' + val - 1);
                k -= val;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string getSmallestString(int n, int k)
    {
        string res = string(n, 'a'); //initialising all a's
        k -= n; //a -> 1, initially all a's so subtract n*1
        int i = n - 1;
        while (k > 0)
        {
            if (k >= 25)
            {
                res[i--] = 'z';
                k -= 25;
            }
            else
            {
                res[i--] = 'a' + k;
                k = 0;
            }
        }

        return res;
    }
};
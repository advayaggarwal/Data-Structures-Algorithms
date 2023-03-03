//Time complexity - O((logN)!∗logN)
//Space complexity - O(logN)
class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        return permute(s, 0);
    }

    bool isPowerOf2(string &s) //O(logN)
    {
        if (s[0] == '0') return false;
        int no = stoi(s);
        return (no & (no - 1)) == 0;
    }

    bool permute(string &s, int i)
    {
        if (i == s.size())   return isPowerOf2(s);

        for (int j = i; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            if (permute(s, i + 1)) return true;
            swap(s[i], s[j]);
        }

        return false;
    }
};

//Time complexity - O(log^2 N). There are logN different candidate powers of 2, and each comparison has O(logN) time complexity
//Space complexity - O(logN)
class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        vector<int>freq(10);
        count(n, freq);

        for (int i = 0; i < 30; i++)
        {
            vector<int>temp(10);
            count(1 << i, temp);
            if (freq == temp) return true;
        }

        return false;
    }

    void count(int n, vector<int>&freq)
    {
        while (n)
        {
            freq[n % 10]++;
            n /= 10;
        }
    }
};
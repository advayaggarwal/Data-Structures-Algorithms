//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string makeGood(string s)
    {
        string res;

        for (char c : s)
        {
            if (res.size() && res.back() != c && (toupper(res.back()) == c or tolower(res.back()) == c))
                res.pop_back();

            else res.push_back(c);
        }

        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string makeGood(string s)
    {
        // Initialize 'end = 0' since the good string is empty.
        int end = 0;
        for (int cur = 0; cur < s.size(); ++cur)
        {
            // If s[cur] makes a pair with the last character s[end - 1] in good string,
            // remove s[end - 1] by decrementing 'end' by 1.
            // Otherwise, add s[cur] to the good string by overwritting s[end] by s[cur].
            if (end > 0 && abs(s[cur] - s[end - 1]) == 32)  end--;
            else
            {
                s[end] = s[cur];
                end++;
            }
        }

        // Once the iteration ends, the string before 'end' is the good string.
        return s.substr(0, end);
    }
};
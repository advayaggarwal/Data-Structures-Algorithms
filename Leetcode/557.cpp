//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        string res;

        while (i < n)
        {
            string temp;
            while (s[i] != ' ' and i < n)
            {
                temp += s[i++];
            }
            i++;
            reverse(temp.begin(), temp.end());

            res += temp + " ";
        }
        res.pop_back();
        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string reverseWords(string s)
    {
        string res, temp;
        stringstream ss(s);

        while (getline(ss, temp, ' '))
        {
            reverse(temp.begin(), temp.end());
            res += temp + ' ';
        }
        res.pop_back();
        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string reverseWords(string& s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};
//Using tokenisation
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders)
    {
        unordered_map<string, int>m;

        for (int i = 0; i < messages.size(); i++)
        {
            string sender = senders[i];
            int count = 0;
            stringstream ss(messages[i]);
            string s;
            while (ss >> s)   count++;
            m[sender] += count;
        }

        int ans = 0;
        string res;
        for (auto &p : m)
        {
            if (p.second > ans or (p.second == ans && p.first > res))
            {
                ans = p.second;
                res = p.first;
            }
        }
        return res;
    }
};


//Counting number of spaces
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < messages.size(); ++i)
        {
            int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;
            mp[senders[i]] += words;
        }
        string ans = "";
        int count = 0;
        for (auto p : mp)
        {
            if (p.second > count or (p.second == count && p.first > ans))
            {
                count = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};
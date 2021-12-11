class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        string ans;
        vector<string>res;

        helper(0, s, ans, res, dict);
        return res;
    }

    void helper(int i, string &s, string ans, vector<string>&res, unordered_set<string>&dict)
    {
        if (i >= s.size())
        {
            ans.pop_back(); //remove the trailing space
            res.push_back(ans);
            return ;
        }

        string temp;
        for (int j = i; j < s.size(); j++)
        {
            //get every substring and check if it exists in set
            temp += s[j];

            if (dict.find(temp) != dict.end())
            {
                //we have got a word in dict
                //explore more and get other substrings
                helper(j + 1, s, ans + temp + " ", res, dict);
            }
        }
    }
};

//Using DP
class Solution {
public:
    unordered_map<string, vector<string>>dp;
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        if (dp.find(s) != dp.end())  return dp[s];
        vector<string>res;

        for (string word : wordDict)
        {
            if (s.substr(0, word.size()) == word)
            {
                if (s.size() == word.size())
                {
                    res.push_back(s);
                }

                else
                {
                    vector<string>temp = wordBreak(s.substr(word.size()), wordDict);

                    for (string t : temp)
                    {
                        res.push_back(word + " " + t);
                    }
                }
            }
        }

        return dp[s] = res;
    }
};
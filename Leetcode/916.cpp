//Time complexity - O(m*n*k)
//Space complexity - O(1)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<string>res;

        for (string word : words1)
        {
            int i;
            vector<int>count(26);
            for (char c : word)  count[c - 'a']++;
            bool flag = true;

            for (i = 0; i < words2.size() && flag; i++)
            {
                vector<int>freq(26);
                for (char c : words2[i]) freq[c - 'a']++;

                for (int j = 0; j < 26; j++)
                {
                    if (freq[j] > count[j])
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if (i == words2.size() && flag)  res.push_back(word);
        }

        return res;
    }
};

//Time complexity - O((m+n)*k)
//Space complexity - O(1)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<string>res;
        vector<int>freq(26);
        for (string w : words2)
        {
            vector<int>temp(26);
            for (char c : w)
            {
                temp[c - 'a']++;
                freq[c - 'a'] = max(freq[c - 'a'], temp[c - 'a']);
            }
        }

        for (string word : words1)
        {
            vector<int>count(26);
            for (char c : word)  count[c - 'a']++;
            int j;
            for (j = 0; j < 26; j++)
            {
                if (freq[j] > count[j])  break;
            }

            if (j == 26)  res.push_back(word);
        }

        return res;
    }
};
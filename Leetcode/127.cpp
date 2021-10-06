class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, bool>visited;

        int n = wordList.size();
        for (int i = 0; i < n; i++)  visited[wordList[i]] = false;

        int level = 1;
        queue<string>q;
        q.push(beginWord);
        visited[beginWord] = true;

        while (!q.empty())
        {
            int len = q.size();

            for (int i = 0; i < len; i++)
            {
                string s = q.front();
                q.pop();

                if (s == endWord)    return level;

                for (int j = 0; j < s.size(); j++)
                {
                    char c = s[j];

                    for (int i = 0; i < 26; i++)
                    {
                        s[j] = 'a' + i;

                        if (visited.find(s) != visited.end() && visited[s] == false)
                        {
                            q.push(s);
                            visited[s] = true;
                        }
                    }
                    s[j] = c;
                }
            }

            level++;
        }

        return 0;
    }
};
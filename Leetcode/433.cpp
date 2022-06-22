//BFS
//Time complexity - O(3^n)
//Space complexity - O(n)
class Solution {
public:
    int minMutation(string start, string end, vector<string>&bank)
    {
        if (start == end)    return 0;

        unordered_set<string>visited;
        unordered_set<string>valid;
        for (string &s : bank)   valid.insert(s);

        if (!valid.count(end))   return -1;

        vector<char>edges = {'A', 'C', 'G', 'T'};

        queue<string>q;
        q.push(start);
        visited.insert(start);
        int steps = 0;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                string s = q.front();
                q.pop();
                if (s == end)    return steps;

                for (int i = 0; i < s.size(); i++)
                {
                    char prev = s[i];

                    for (auto ch : edges)
                    {
                        s[i] = ch;
                        if (!visited.count(s) && valid.count(s))
                        {
                            visited.insert(s);
                            q.push(s);
                        }
                    }

                    s[i] = prev;
                }
            }

            steps++;
        }

        return -1;
    }
};
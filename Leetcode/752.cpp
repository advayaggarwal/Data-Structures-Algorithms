//BFS
/*
Time: O(N^2 * A^N + D), where N is number of dials (4 in our case), A is number of alphabet (10 in our case), D is size of deadends.
There are 10^4 possible combinations => O(A^N)
To get neighbors, for each combination, we are looping 4 times (which is N) and in each iteration, there are substring operations which costs O(N) => O(N^2)
Total O(D) to create the hashset
Space: O(A^N), in worst case equal to number of combinations.

*/
class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        if (target == "0000")    return 0;

        unordered_set<string>visited;
        unordered_set<string>notValid;
        for (string &s : deadends)   notValid.insert(s);

        if (notValid.count("0000"))  return -1;

        queue<string>q;
        q.push("0000");
        visited.insert("0000");
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                string s = q.front();
                q.pop();
                if (s == target) return steps;

                for (int i = 0; i < 4; i++)
                {
                    char c = s[i];
                    int ch = s[i] - '0';

                    char op1 = ((ch + 1) % 10) + '0';
                    char op2 = ((ch - 1 + 10) % 10) + '0';

                    s[i] = op1;

                    if (!visited.count(s) && !notValid.count(s))
                    {
                        visited.insert(s);
                        q.push(s);
                    }

                    s[i] = op2;
                    if (!visited.count(s) && !notValid.count(s))
                    {
                        visited.insert(s);
                        q.push(s);
                    }

                    s[i] = c;
                }
            }

            steps++;
        }

        return -1;
    }
};
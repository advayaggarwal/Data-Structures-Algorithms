//Time complexity - O(n*m)
//Space complexity - O(1)
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings)
    {
        int n = s.size(), m = sub.size();
        vector<vector<bool>>allowed(128, vector<bool>(128)); //contains only letters and digits
        //allowed[i][j] tells whether we can replace i with j or not

        for (int i = 0; i < 128; i++)    allowed[i][i] = true; //means any char can be replaced with itself, it means no replacement

        for (auto v : mappings)  allowed[v[0]][v[1]] = true; //v[0] can be replaced with v[1]

        for (int i = 0; i <= n - m; i++) //comparing every substring of size m in s
        {
            // i.....i + m - 1
            int j;
            for (j = 0; j < m; j++)
            {
                //match sub[j] with s[i+j], with or without replacement
                if (!allowed[sub[j]][s[i + j]])    break;
            }

            if (j == m)  return true; //it means every char matched
        }

        return false;
    }
};

//Time complexity - O(n*m)
//Space complexity - O(1)
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings)
    {
        int n = s.size(), m = sub.size();
        unordered_map<char, unordered_set<char>>allowed;
        //allowed[i][j] tells whether we can replace i with j or not

        for (auto v : mappings)  allowed[v[0]].insert(v[1]); //v[0] can be replaced with v[1]

        for (int i = 0; i <= n - m; i++) //comparing every substring of size m in s
        {
            // i.....i + m - 1
            int j;
            for (j = 0; j < m; j++)
            {
                if (sub[j] == s[i + j])    continue; //already equal, so no need to replace
                //match sub[j] with s[i+j], with or without replacement
                if (!allowed[sub[j]].count(s[i + j]))    break;
            }

            if (j == m)  return true; //it means every char matched
        }

        return false;
    }
};
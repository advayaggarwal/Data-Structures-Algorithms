//Time Complexity: O(N*K*logK), where N is the length of strs, and K is the maximum length of a string in strs.
//The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(K*logK) time.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;

        int n = strs.size();

        for (int i = 0; i < n; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            //if we sort the anagrams they will be the same, eg tea, ate will be aet
            //so those who have same key will be a part of same vector
            m[s].push_back(strs[i]);
        }

        vector<vector<string>>res(m.size());
        //res's size will be the size of map
        int i = 0;
        for (auto e : m)
        {
            for (auto x : e.second)  res[i].push_back(x);
            i++;
        }

        return res;
    }
};


//Using count array so that we don't have to sort
//Time complexity - O(N*K), where N is the length of strs, and K is the maximum length of a string in strs.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;

        int n = strs.size();

        unordered_map<string, vector<string>>m;

        for (int i = 0; i < n; i++)
        {
            vector<int>count(26, 0);

            for (char c : strs[i])
            {
                count[(c - 'a')]++;
            }
            string key;
            for (int j = 0; j < 26; j++) key += string(count[j], j + 'a');
            //string(count,char), basically it will sort the key, same as count sort
            //cout << key << endl;
            m[key].push_back(strs[i]);
        }

        for (auto e : m)   res.push_back(e.second);

        return res;
    }
};
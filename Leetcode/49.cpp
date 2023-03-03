//Time Complexity: O(N*K*logK), where N is the length of strs, and K is the maximum length of a string in strs.
//The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(K*logK) time.
//Space complexity - O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>>m;

        for (string s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }

        vector<vector<string>>res;
        for (auto p : m) res.push_back(p.second);
        return res;
    }
};

//Using count array so that we don't have to sort
//Time complexity - O(N*K), where N is the length of strs, and K is the maximum length of a string in strs.
//Space complexity - O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>>m;

        for (string s : strs)
        {
            vector<int>freq(26);
            for (char c : s) freq[c - 'a']++;
            string temp;
            for (int i = 0; i < 26; i++) temp += string(freq[i], 'a' + i);
            //string(count,char) will sort the key, same as count sort, freq of a followed by b, c, .. z
            //eg string(3, 'b') = bbb
            m[temp].push_back(s);
        }

        vector<vector<string>>res;
        for (auto p : m) res.push_back(p.second);
        return res;
    }
};
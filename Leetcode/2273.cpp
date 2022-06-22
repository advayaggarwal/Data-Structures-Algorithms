//With sorting
//Time complexity - O(m*logm*n), where n is #strings and m is maximum length of string
//Space complexity - O(n)
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words)
    {
        unordered_map<string, vector<int>>m;

        for (int i = 0; i < words.size(); i++)
        {
            string key = words[i];
            sort(key.begin(), key.end());
            m[key].push_back(i);
        }

        vector<int>index;

        for (auto &p : m)
        {
            vector<int>v = p.second;
            index.push_back(v[0]);
            int last = v[0];
            for (int i = 1; i < v.size(); i++)
            {
                if (v[i] != last + 1)  index.push_back(v[i]);
                last = v[i];
            }
        }

        sort(index.begin(), index.end());

        vector<string>res;
        for (int i = 0; i < index.size(); i++)
        {
            res.push_back(words[index[i]]);
        }

        return res;
    }
};

//Without sorting
//Time complexity - O(m*n), where n is #strings and m is maximum length of string
//Space complexity - O(1)
vector<string> removeAnagrams(vector<string>& A) {
    vector<string> ans;
    int n = size(A);
    for (int i = 0; i < n;) {
        int j = i + 1;
        while ( j < n and isang(A[i], A[j])) j++;
        ans.push_back(A[i]);
        i = j;
    }
    return ans;
}
//function for checking if two string are anagrams or not
bool isang(string p, string q) {
    vector<int> cnt(26);
    int res = 0;
    for (auto i : p) cnt[i - 'a']++;
    for (auto i : q) cnt[i - 'a']--;
    for (auto i : cnt) if (i != 0) return false;
    return true;
}
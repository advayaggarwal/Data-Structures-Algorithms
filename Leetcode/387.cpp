//Time complexity - O(n), 2 string traversals
//Space complexity - O(26) ~ O(1)
class Solution {
public:
    int firstUniqChar(string s) {

        vector<int>freq(26, 0);

        for (char ch : s)  freq[ch - 'a']++;

        int n = s.size();
        for (int i = 0; i < n; i++)  if (freq[s[i] - 'a'] == 1)   return i;

        return -1;
    }
};

//Time complexity - O(n), 1 string traversal
//Space complexity - O(26) ~ O(1)
class Solution {
public:
    int firstUniqChar(string s) {

        vector<pair<int, int>>occurrence(26); //{freq, latest_index}
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            occurrence[s[i] - 'a'].first++;
            occurrence[s[i] - 'a'].second = i;
        }

        int index = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (occurrence[i].first == 1)    index = min(index, occurrence[i].second);
        }

        return index == INT_MAX ? -1 : index;
    }
};
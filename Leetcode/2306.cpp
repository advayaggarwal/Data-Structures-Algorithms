//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    long long distinctNames(vector<string>& ideas)
    {
        unordered_set<string>hashSet(ideas.begin(), ideas.end());
        int n = ideas.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string s1 = ideas[i], s2 = ideas[j];
                swap(s1[0], s2[0]);
                if (!hashSet.count(s1) && !hashSet.count(s2))    ans += 2; //two strings will be s1+s2 and s2+s1
            }
        }

        return ans;
    }
};

/*
    Making Groups of prefix and their suffix
    Any idea = first letter + postfix string.
    We can group all ideas by their first letter.

    If two ideas ideas[i] and ideas[j] share a common postfix string,
    then ideas[i] can not pair with any idea that starts with ideas[j][0]
    and ideas[j] can not pair with any idea that starts with ideas[i][0].
*/
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    long long distinctNames(vector<string>& ideas)
    {
        unordered_set<string>hashSet[26];
        int n = ideas.size();

        for (int i = 0; i < n; i++)  hashSet[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
        long long ans = 0;

        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                long long c1 = 0 , c2 = 0;
                for (auto e : hashSet[i])
                {
                    if (!hashSet[j].count(e))    c1++;
                }
                for (auto e : hashSet[j])
                {
                    if (!hashSet[i].count(e))    c2++;
                }

                ans += c1 * c2;
            }
        }

        return 2 * ans; //each pair corressponds to two, s1, s2 -> s1 + s2, and s2 + s1
    }
};
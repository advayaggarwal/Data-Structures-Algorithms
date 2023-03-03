//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        vector<int>res;
        int n = changed.size();
        if (n & 1)   return res;

        map<int, int>m;
        for (int i = 0; i < n; i++)  m[changed[i]]++;

        while (!m.empty())
        {
            auto it = m.begin();
            int no = it->first;
            m[no]--;
            if (m[no] == 0)  m.erase(it);
            if (!m.count(2 * no))  return {};
            else
            {
                m[2 * no]--;
                if (m[2 * no] == 0) m.erase(2 * no);
            }

            res.push_back(no);
        }

        return res;
    }
};

//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        vector<int>res;
        int n = changed.size();
        if (n & 1)   return res;

        unordered_map<int, int>m;
        for (int i = 0; i < n; i++)  m[changed[i]]++;
        sort(changed.begin(), changed.end());

        for (int num : changed)
        {
            if (m[num] == 0) continue;
            if (m[2 * num] == 0)   return {};
            if (m[num] && m[2 * num])
            {
                m[num]--;
                m[2 * num]--;
                res.push_back(num);
            }
        }

        return res;
    }
};
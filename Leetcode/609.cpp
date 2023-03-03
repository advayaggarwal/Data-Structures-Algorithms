class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>m;

        for (auto path : paths)
        {
            stringstream ss(path);
            string root, s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' '))
            {
                string fileName = root + '/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                m[fileContent].push_back(fileName);
            }
        }

        for (auto p : m)
        {
            if (p.second.size() > 1)
            {
                res.push_back(p.second);
            }
        }

        return res;
    }
};
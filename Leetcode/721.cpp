class DSU {
public:
    vector<int>rank, leader;
    DSU(int n)
    {
        rank = vector<int>(n, 1);
        leader = vector<int>(n, -1);
    }
    int findLeader(int x)
    {
        if (leader[x] == -1) return x;
        return leader[x] = findLeader(leader[x]);
    }
    void unionByRank(int x, int y)
    {
        int leader1 = findLeader(x);
        int leader2 = findLeader(y);

        if (leader1 == leader2)  return;

        if (rank[leader1] < rank[leader2])   leader[leader1] = leader2;
        else if (rank[leader1] > rank[leader2])  leader[leader2] = leader1;
        else
        {
            leader[leader2] = leader1;
            rank[leader1]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int>mapMailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++) //emails start from 1
            {
                string mail = accounts[i][j];
                if (!mapMailNode.count(mail))    mapMailNode[mail] = i;
                else dsu.unionByRank(i, mapMailNode[mail]);
            }
        }

        vector<string>mergedMails[n];
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = dsu.findLeader(it.second);
            mergedMails[node].push_back(mail);
        }
        vector<vector<string>>res;

        for (int i = 0; i < n; i++)
        {
            if (mergedMails[i].size() == 0)  continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string>mails;
            mails.push_back(accounts[i][0]);
            for (string m : mergedMails[i])  mails.push_back(m);
            res.push_back(mails);
        }

        return res;
    }
};
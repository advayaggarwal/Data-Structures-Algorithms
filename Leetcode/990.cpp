class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {
        vector<int>leader(26, -1), rank(26, 1);

        for (string e : equations)
        {
            if (e[1] == '=')
            {
                Union(e[0] - 'a', e[3] - 'a', leader, rank);
            }
        }

        for (string e : equations)
        {
            if (e[1] == '!')
            {
                int l1 = find(e[0] - 'a', leader);
                int l2 = find(e[3] - 'a', leader);
                if (l1 == l2)    return false;
            }
        }

        return true;
    }

    int find(int x, vector<int>&leader)
    {
        if (leader[x] == -1) return x;
        return leader[x] = find(leader[x], leader);
    }

    void Union(int x, int y, vector<int>&leader, vector<int>&rank)
    {
        int l1 = find(x, leader);
        int l2 = find(y, leader);

        if (l1 != l2)
        {
            if (rank[l1] < rank[l2]) leader[l2] = l1;
            else if (rank[l2] < rank[l1])    leader[l1] = l2;
            else
            {
                leader[l2] = l1;
                rank[l1]++;
            }
        }
    }
};
class Solution {
public:
    bool isValidSerialization(string preorder) {

        stringstream iss(preorder);

        vector<string>nodes;
        string node;

        while (getline(iss, node, ','))
        {
            nodes.push_back(node);
        }

        int capacity = 1;

        for (int i = 0; i < nodes.size(); i++)
        {
            capacity --;

            if (capacity < 0)    return false;

            if (nodes[i] != "#") capacity += 2;
        }

        return capacity == 0;
    }
};
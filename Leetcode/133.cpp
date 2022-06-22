/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (!node)   return NULL;

        queue<Node*>q;
        q.push(node);
        unordered_map<Node*, Node*>m;
        m[node] = new Node(node->val);

        while (!q.empty())
        {
            Node *t = q.front();
            q.pop();

            for (auto nbr : t->neighbors)
            {
                if (!m.count(nbr))
                {
                    q.push(nbr);
                    m[nbr] = new Node(nbr->val);
                }
                m[t]->neighbors.push_back(m[nbr]);
            }
        }

        return m[node];
    }
};

//DFS
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (!node)   return NULL;
        unordered_map<Node*, Node*>m;
        dfs(node, m);
        return m[node];
    }

    void dfs(Node *node, unordered_map<Node*, Node*>&m)
    {
        m[node] = new Node(node->val);

        for (auto nbr : node->neighbors)
        {
            if (!m.count(nbr))    dfs(nbr, m);
            m[node]->neighbors.push_back(m[nbr]);
        }
    }
};
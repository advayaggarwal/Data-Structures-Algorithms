//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    Node* connect(Node* root)
    {
        if (!root)   return NULL;

        queue<Node*>q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            Node *dummy = new Node(0);

            while (sz--)
            {
                Node *node = q.front();
                q.pop();
                dummy->next = node;
                dummy = dummy->next;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return root;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    Node* connect(Node* root)
    {
        if (!root)   return NULL;

        Node *head = root;

        while (head)
        {
            Node *dummy = new Node(0);
            Node *temp = dummy;
            while (head)
            {
                if (head->left)
                {
                    temp->next = head->left;
                    temp = temp->next;
                }

                if (head->right)
                {
                    temp->next = head->right;
                    temp = temp->next;
                }

                head = head->next;
            }

            head = dummy->next;
        }

        return root;
    }
};
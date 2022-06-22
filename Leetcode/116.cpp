//DFS - Preorder traversal
//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    Node* connect(Node* root)
    {
        if (!root)   return NULL;

        if (root->left) root->left->next = root->right;

        if (root->right && root->next)   root->right->next = root->next->left;

        root->left = connect(root->left);
        root->right = connect(root->right);

        return root;
    }
};


//BFS - Levelorder traversal
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
            for (int i = 0; i < sz; i++)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left)
                {
                    q.push(temp->left);
                    temp->left->next = temp->right;
                }
                if (temp->right)
                {
                    q.push(temp->right);
                    if (temp->next)  temp->right->next = temp->next->left;
                }

                if (i == sz - 1)
                {
                    temp->next = NULL;
                }
            }
        }

        return root;
    }
};

//Easy to implement solution
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
                Node *temp = q.front();
                q.pop();

                dummy->next = temp;
                dummy = dummy->next;

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return root;
    }
};

//Levelorder traversal without queue - using next pointers
//Similar to a level-order traversal, even you are not allowed to use a queue, the next pointer provides you
//with a way to move to the next node in the same level.
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    Node* connect(Node* root) {
        Node *pre = root, *cur;
        while (pre) {
            cur = pre;
            while (cur && cur -> left) { // traversing the current level
                cur -> left -> next = cur -> right;
                if (cur -> next) {
                    cur -> right -> next = cur -> next -> left;
                }
                cur = cur -> next;
            }
            pre = pre -> left; //moving onto the next level
        }
        return root;
    }
};
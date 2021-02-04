/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)   return NULL;
        Node *iter = head;

        //Copy nodes
        while (iter)
        {
            Node *temp = iter->next;
            iter->next = new Node(iter->val);
            iter->next->next = temp;
            iter = temp;
        }

        iter = head;

        //Assigning random pointers
        while (iter)
        {
            if (iter->random)
            {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        //Segregate both the lists
        iter = head;
        Node *pseudohead = head->next;

        while (iter)
        {
            Node *temp = iter->next->next;
            Node *copy = iter->next;
            iter->next = temp;
            if (copy->next)  copy->next = copy->next->next;
            iter = iter->next;
        }
        return pseudohead;
    }

};
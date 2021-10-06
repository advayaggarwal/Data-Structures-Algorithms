//Time complexity - O(NlogN)
//Space complexity - O(logN)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);

        ListNode *slow = head, *fast = head->next;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;

        TreeNode *root = new TreeNode(mid->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};


//Time complexity - O(N)
//Space complexity - O(logN)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (!head)   return NULL;

        ListNode *temp = head;
        int n = 0;

        while (temp)
        {
            n++;
            temp = temp->next;
        }

        return build(head, n);

    }

    TreeNode* build(ListNode* &head, int n)
    {
        if (n == 0)  return NULL;

        TreeNode *root = new TreeNode();

        root->left = build(head, n / 2);

        root->val = head->val;
        head = head->next;

        root->right = build(head, (n - 1) / 2);

        return root;
    }
};
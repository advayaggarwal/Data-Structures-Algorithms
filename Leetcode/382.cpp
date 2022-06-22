//Space complexity - O(n)
class Solution {
public:
    vector<int>list;
    Solution(ListNode* head) //O(n)
    {
        ListNode *t = head;
        while (t)
        {
            list.push_back(t->val);
            t = t->next;
        }
    }

    int getRandom() //O(1)
    {
        int i = rand() % (list.size());
        return list[i];
    }
};
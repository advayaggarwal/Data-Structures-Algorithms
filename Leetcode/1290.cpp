//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head)
    {
        int ans = 0;
        while (head)
        {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};

//Using Bitwise Operators as they are fast
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head)
    {
        int ans = 0;
        while (head)
        {
            ans = (ans << 1) | head->val;
            head = head->next;
        }
        return ans;
    }
};
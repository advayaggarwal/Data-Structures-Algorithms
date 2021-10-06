class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL)    return NULL;

        ListNode *t = head;
        int count  = 0;
        while (t && count != k) { // find the k+1 node
            t = t->next;
            count++;
        }
        if (count == k) {
            ListNode *prev = NULL, *current = head, *temp;
            while (current && count > 0)
            {
                temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
                count--;
            }

            if (temp)    head->next = reverseKGroup(temp, k);

            return prev;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count = 0;
        ListNode *ptr = head;
        
        while(count < k && ptr)
        {
            ptr = ptr->next;
            count++;
        }
        
        if(count == k)
        {
            ListNode *rev_head = reverse(head, k);
            head->next = reverseKGroup(ptr, k);
            
            return rev_head;
        }
        
        return head;
    }
    
    ListNode* reverse(ListNode *head, int k)
    {
        if(!head or !head->next)    return head;
        
        ListNode *prev = NULL, *current = head;
        int count = 0;
        while(current && count < k)
        {
            ListNode *next = current->next;
            count++;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};

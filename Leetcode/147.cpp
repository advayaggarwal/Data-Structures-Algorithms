//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *prev = start, *current = head;

        while (current)
        {
            if (current->next && current->next->val < current->val)
            {
                //Insert current->next at right place
                while (prev->next && prev->next->val < current->next->val) prev = prev->next;
                //yeah we found the correct place for current->next

                //Rearrangning the pointers
                ListNode *temp = prev->next;
                prev->next = current->next;
                current->next = current->next->next;
                prev->next->next = temp;

                // Again point prev to start for next iteration
                prev = start;
            }

            else current = current->next;
        }

        return start->next;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode *start = new ListNode(0);
        ListNode *current = head;

        while (current)
        {
            // At each iteration, we insert an element into the resulting list.
            ListNode *prev = start;

            // find the position to insert the current node
            while (prev->next && prev->next->val < current->val) prev = prev->next;
            //yeah we found the correct place for current->next

            //Rearrangning the pointers
            ListNode *cur_next = current->next;

            // insert the current node to the new list
            current->next = prev->next;
            prev->next = current;

            // moving on to the next iteration
            current = cur_next;
        }

        return start->next;
    }
};
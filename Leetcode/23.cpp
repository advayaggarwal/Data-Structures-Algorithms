//Merge with divide and conquer
//We have merge in pairs (first,last), (second, last second), and so on... and store their respective results in the first member of each pair

//eg 1 2 3 4 5 6 7 8 9 10, these are 10 linked lists in lists vector
//After step 1 ---- 1 2 3 4 5 ---- (1,10)->1, (2,9)->2, (3,8)->3, (4,5)->4, (5,6)->5
//After step 2 ---- 1 2 3 ---- (1,5)->1, (2,4)->2, 3 as it is
//After step 3 ---- 1 2 ---- (1,3)->1, 2 as it is
//Final step ---- 1 ---- (1,2)->1

//Every time no is linked lists in becoming half and each step takes O(n) to merge
//Time complexity - O(n*logk), where n is total nodes and k is no. of linked lists
//Space complexity - O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)    return NULL;
        if (k == 1)    return lists[0];
        int i = 0, last = k - 1;
        int j;
        while (last)
        {
            i = 0;
            j = last;
            while (i < j)
            {
                lists[i] = merge(lists[i], lists[j]);
                i++;
                j--;
            }
            last = j;
        }

        return lists[0];
    }


    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        current->next = l1 ? l1 : l2;

        return dummy->next;
    }
};



/** MIN HEAP
 Time complexity - O(N*logK), every node got push into min heap 1 time and popped from min heap 1 time
 and at max there are K nodes in min heap at any point of time, so push and pop operations are O(logK)
 so every node contributes 2*logK time therefore total complexity - O(2*N*logK) = O(N*logK)
 Space complexity - O(K) for min heap otherwise we have done inplace sorting
 */
class Solution {
public:

    static bool compare(ListNode *&a, ListNode *&b)
    {
        return a->val > b->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();
        if (k == 0)    return NULL;
        if (k == 1)    return lists[0];

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)*> pq(compare); //please note the syntax here

        for (int i = 0; i < k; i++) if (lists[i]) pq.push(lists[i]);

        ListNode *head = new ListNode(0);
        ListNode *temp = head;

        while (pq.size() > 0)
        {
            ListNode *p = pq.top();
            pq.pop();
            temp->next = p;
            temp = temp->next;
            if (p->next) pq.push(p->next);
        }

        return head->next;
    }
};

//Same as above solution just another syntax for custom comparator function using operator overloading
class Solution {
public:

    struct compare
    {
        bool operator()(ListNode* &a, ListNode* &b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();
        if (k == 0)    return NULL;
        if (k == 1)    return lists[0];

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i = 0; i < k; i++) if (lists[i]) pq.push(lists[i]);

        ListNode *head = new ListNode(0);
        ListNode *temp = head;

        while (pq.size() > 0)
        {
            ListNode *p = pq.top();
            pq.pop();
            temp->next = p;
            temp = temp->next;
            if (p->next) pq.push(p->next);
        }

        return head->next;
    }
};



//Time complexity - O(n*logk), where n is total nodes and k is no. of linked lists
//Space complexity - O(1)

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
        return nullptr;
    }
    while (lists.size() > 1) {
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
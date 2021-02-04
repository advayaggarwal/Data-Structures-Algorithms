/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s = "";
        while (head)
        {
            char d = char(head->val + '0');
            s += string(1, d);
            head = head->next;
        }
        int i = stoi(s, 0, 2);
        return i;
    }
};
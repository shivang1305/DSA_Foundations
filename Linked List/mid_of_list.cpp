/*
                                                                                 Date: 11-Oct-2020

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.
*/

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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL) //single node in linked list
            return head;

        else {
            ListNode* fast = head;
            ListNode* slow = head;

            while(fast->next != NULL && fast->next->next != NULL) {
                fast = fast->next->next; //fast moves 2 steps at a time
                slow = slow->next;
            }

            if(fast->next != NULL) //it checks if the size of LL is even or not
                slow = slow->next; //to return the second middle element in case of even size of LL

        return slow;
        }
    }
};

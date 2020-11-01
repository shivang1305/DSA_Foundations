/*
                                                                                 Date: 11-Oct-2020

                                                                                 Given the head of a linked list, remove the nth node from the end of the list and return its head.

                                                                                 Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        //when there is only single element in the linked list
        if(head->next == NULL)
            head = NULL;

        //when last element is to be removed from the linked list
        else if(n == 1) {
            fast = fast->next;

            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = NULL;
            delete(fast);
        }

        else {
           for(int i=1; i<n; i++)
            fast = fast->next;

            while(fast->next != NULL) {
                slow = slow->next;
                fast = fast->next;
            }

            slow->val = slow->next->val;
            slow->next = slow->next->next;
        }

        return head;
    }
};

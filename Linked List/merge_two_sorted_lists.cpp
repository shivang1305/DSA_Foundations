/*
                                                                                  Date: 11-Oct-2020

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode();
        ListNode* head = l;

        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                l->next = l1;
                l1 = l1->next;
            }
            else {
                l->next = l2;
                l2 = l2->next;
            }

            l = l->next; //moves the list pointer forward
        }

        //for all the remaining elements of the first list
        while(l1 != NULL) {
            l->next = l1;
            l1 = l1->next;
            l = l->next;
        }

        //for all the remaining elements of the second list
        while(l2 != NULL) {
            l->next = l2;
            l2 = l2->next;
            l = l->next;
        }

        return head->next;
    }
};

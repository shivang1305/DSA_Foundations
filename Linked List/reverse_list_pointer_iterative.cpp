/*
                                                                                 Date: 10-Oct-2020
Reverse the linked list by both recursive and iterative approach.
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

    ListNode* revList(ListNode* prev, ListNode* curr, ListNode* ptr) {
        if(curr == NULL) //base case
            return prev;

        ptr = curr->next;

        curr->next = prev;
        prev = curr;
        curr = ptr;

        return revList(prev, curr, ptr); //recursive call

    }

    ListNode* reverseList(ListNode* head) {

//         /*ITERATIVE APPROACH to reverse a linked list*/
        /*---------------------------------------------------------------------------------------------*/
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ptr;

        while(curr != NULL) {
            ptr = curr->next; //to store the address of next element before breaking the link

            curr->next = prev;
            prev = curr;
            curr = ptr; //to move the curr forward in the orignal list
        }

        head = prev; //putting the head of reversed linked list pointing to last element of orignal linked list

        return head;
        /*---------------------------------------------------------------------------------------------*/

        /*RECURSIVE APPROACH to reverse a linked list*/

        ListNode* n = revList(NULL, head, NULL);
        return n;
    }
};

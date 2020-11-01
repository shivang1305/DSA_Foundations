/*
                                                                                 Date: 10-Oct-2020

Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        /*SWAPPING ONLY A SINGLE VALUE AND SETTING APPROPRIATE LINK*/

        node->val = node->next->val; //swaps the adjacent values of the linked list
        node->next = node->next->next; //setting the link of node appropriatly so that no furthur swaaping is required.

        /*ITERATIVELY SWAPPING ALL THE VALUES OF THE LINKED LIST TILL THE END*/

        //rather than breaking and forming new links we swapped the adjacent values of the list
        while(node->next->next != NULL) {
            node->val = node->next->val;
            node = node->next;
        }

        node->val = node->next->val; //to swap the last value of list
        node->next = NULL;
    }
};

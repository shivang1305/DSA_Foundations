/*
                                                                                  Date: 16-Oct-2020
Given a singly linked list, determine if it is a palindrome.
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
    /* Recursive Approach */
    bool isPalindromeHelper(ListNode* right) {
        if(right == NULL) //till the end of the list
            return true;

        bool prevResult = isPalindromeHelper(right->next);

        if(prevResult == false) //to ensure that values compared till now fulfills the condition for palindrome
            return false;

        else if(left->val != right->val)
            return false;

        left = left->next; //moving data member forward

        return true;
    }

    ListNode* left; //declared as data member so that it loads into the heap not in stack memory unlike right ptr

    bool isPalindrome(ListNode* head) {
        left = head;
        return isPalindromeHelper(head);
    }
};

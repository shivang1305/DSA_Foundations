/*  Add two numbers (LEETCODE - Med)                                              Date: 17-Oct-2020
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* tmp = res;

        int sum, data;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) { //till the end of both the numbers
            if(l1 == NULL) { //if any one number ends
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else if(l2 == NULL) {
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            //obtaing carry and orignal number to be put in result linked list
            carry = sum / 10;
            data = sum % 10;

            ListNode* node  = new ListNode(data);
            if(res == NULL) {
                res = node;
                tmp = node;
            }
            else {
                tmp->next = node;
                tmp = node;
            }
        }

        //to resolve the final carry
        if(carry > 0) {
            ListNode* node = new ListNode(carry);
            tmp->next = node;
            tmp = node;
        }

        return res;
    }
};

/*                                                                               Date: 13-Oct-2020
  LEETCODE - 358. Odd Even List  (medium)

  Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

  You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
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
    ListNode* oddEvenList(ListNode* head) {
        //base case
        if(head == NULL)
            return head;

        ListNode* oddList = new ListNode(-1);
        ListNode* evenList = new ListNode(-1);

        ListNode* odd = oddList;
        ListNode* even = evenList;

        ListNode* ptr = head;

        int flag = 0;

        while(ptr != NULL) {
            if(flag == 0) {
                //put the element in odd list
                ListNode* oddNode = new ListNode(ptr->val);
                odd->next = oddNode;
                odd = odd->next;
                flag = 1;
            }
            else if(flag == 1) {
                //put the element in even list
                ListNode* evenNode = new ListNode(ptr->val);
                even->next = evenNode;
                even = even->next;
                flag = 0;
            }
            ptr = ptr->next;
        }

        if(oddList->next != NULL && evenList->next != NULL) //both the lists are having more than one element
            odd->next = evenList->next; //merging both the lists
        else if(oddList->next != NULL) //no element is there in even list
            return oddList->next;
        else if(evenList->next != NULL) //no element is there in odd list
            return evenList->next;

        return oddList->next;
    }
};

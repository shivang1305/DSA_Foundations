/*
                                                                                  Date: 12-Oct-2020
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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL) //if list is empty
            return head;

        /* APPROACH 1: BY TWISTING AND SWAPPING THE VALUES OF NODES OF LINKED LIST */

/*         ListNode* ptr = head;

        while(ptr->next != NULL) {
            if(ptr->val == ptr->next->val)
                ptr->next = ptr->next->next; //break the link and make the new link by skipping the adjacent element
            else
                ptr = ptr->next;
        }

        return head;
*/

        /* APPROACH 2: BY CREATING A NEW LIST AND PUTTING ONLY UNIQUE VALUES IN IT */

        ListNode* list = new ListNode(head->val); //putting the first element of the list always
        ListNode* hList = list;//to return the head of LL we must have a pointer pointing at head of newly created LL

        head = head->next;

        while(head != NULL) {
            if(head->val != list->val) { //for all unique values
                ListNode* newNode = new ListNode(head->val); //create a new node
                list->next = newNode; //adding new node to the List
                list = list->next;
            }
            head = head->next;
        }

        return hList;
    }
};

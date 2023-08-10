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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = NULL; // assigning dummy node to null
        while (head != NULL)
        {
            ListNode *next = head->next;
            head->next = newHead; /*reversing link, i.e. making 2nd node point to first node( in previous step we made the dummy pointer point to previous node..
  1. for better understanding see from 2nd iteration. in first iteration the first node should be pointed to null, so head's next (head-> next) is pointed to newHead which is null.
  2. But from 2nd iteration (see next step) it follows:
  first it will point the next(variable)to next node to be changed, breaks the link by making present node(head) point to previous node(newHead). again moves next to next node, points the present node to previous node. To keeep track of the previous node newHead is used. everytime head is moved to next element and newHead will be the previous element to which we point the present element, */
            newHead = head;
            head = next;
        } // we stop the process when head points to null
        return newHead;
    }
};
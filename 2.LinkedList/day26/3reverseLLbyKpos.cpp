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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // edge cases
        if (!head || !head->next || k == 0)
            return head;

        // length
        ListNode *cur = head;
        int len = 1; // not 0
        while (cur->next != NULL)
        {
            len++;
            cur = cur->next; // moving to last element after incrementing len
        }
        // make last element point to head
        cur->next = head;
        k = k % len;
        k = len - k;
        // go till that node
        while (k--)
            cur = cur->next;

        // make the node as head and braek the connection
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};
// https://leetcode.com/problems/middle-of-the-linked-list/description/
// 2 tortoises
// first goes twice the speed of 2nd. so by the time it reaches the end, the first one will reach exactly the middle
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// sena's
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    while (temp && temp->next)
    {
        if (temp->next->val == temp->val)
        {
            temp->next = temp->next->next; // Skip the duplicate node
            continue;                      // Move to the next iteration immediately
        }
        temp = temp->next; // Move to the next node
    }
    return head;
}

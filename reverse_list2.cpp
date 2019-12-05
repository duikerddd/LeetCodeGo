ListNode* ReverseList(ListNode* head)
{
    //无效输入
    if(head)
        return NULL;
    //一个结点
    if(head->next==NULL)
        return head;
    ListNode* first = NULL;
    ListNode* second = head;
    ListNode* third = head->next;
    while(second!=NULL)
    {
        second->next = first;
        first = second;
        second = third;
        if(third->next!=NULL) //最后一次,third已经是空了
            third = third->next;
    }
    return head;
}

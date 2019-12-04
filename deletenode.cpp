void DeleteNode(ListNode* head,ListNode* del)
{
    //无效输入
    if(!head || !del)
        return;
    //不是尾结点
    if(del->next != NULL)
    {
        ListNode* del_next = del->next;
        del->val = del_next->val;
        del->next = del_next->next;
        
        delete del_next;
        del_next = NULL;
    }   
    //特殊情况: 只有一个结点 
    else if(del == head)
    {
        delete head;
        head = NULL;
        del = NULL;
    }
    //特殊情况: 是尾结点,顺序遍历
    else
    {
        ListNode* cur = head;
        for(;cur->next!=del;cur=cur->next){}
        cur->next = NULL;
        delete del;
        del = NULL;
    }
}

ListNode* CopyList(ListNode* head)
{
    //无效输入
    if(head==NULL)
        return;
    //1.copy到N上
    ListNode* cur = head;
    ListNode* next = cur->next;
    while(cur)
    {
        cur->next = new ListNode(cur->val);
        cur = next;
        if(next!=NULL)
            next = next->next;
    }
    //2.根据N复制N'的任意指针
    cur = head;
    next = cur->next;
    while(cur)
    {
        if(cur->random!=NULL)ha
            next->random = cur->random->next;
        else
            next->random = NULL;
          
        cur = next->next;
        if(cur == NULL)
            break;
        next = cur->next;               
    }   
    //3.分离
    cur = head;
    ListNode* new_head = cur->next; 
    new_cur = new_head;
    
    while(cur)
    {
        cur->next = new_cur->next;
        cur = cur->next;
        if(cur!=NULL)
            new_cur->next = cur->next;
        else
            new_cur->next = NULL;
        new_cur = new_cur->next;        
    } 
    
    return new_head;
}

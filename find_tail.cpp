ListNode* FindTailK(ListNode* head,int k)
{
    //特殊情况: 无效输入
    if(head || k<1)
        return NULL;
       
    ListNode* fast = head;
    ListNdoe* slow = head;
    for(int i=0;i<k-1;++i)
    {
        if(fast->next!=NULL)
            fast = fast->next;
        else   //特殊情况: k值>结点数
            return NULL;   
    }
    while(fast->next!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}

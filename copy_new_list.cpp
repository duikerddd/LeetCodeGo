//复杂链表的复制

//struct ListNode{
//     int val;
//     ListNode* next;
//     ListNode* random;
//};

//1.复制每个节点及其next
//2.复制每个节点的random
//3.分离

ListNode* CopyList(ListNode* head)
{
    if(head == NULL) return NULL;
    
    //1.复制每个节点及其next
    ListNode* cur = head;
    while(cur)
    {
        ListNode* new_node = new ListNode(cur->val);
        new_node->next = cur->next;
        cur->next = new_node;
        
        cur = new_node->next;
    }
    
    //2.复制每个节点的random
    cur = head;
    ListNode* cur_next = head->next;
    while(cur)
    {
        cur_next->random = cur->random->next;
        
        cur = cur_next->next;
        if(cur)
          cur_next = cur->next;
    }
    
    //3.分离
    cur = head;
    ListNode* new_head = head->next;
    cur_next = new_head;
    while(cur)
    {
        cur->next = cur_next->next;
        if(cur->next)
          cur_next->next = cur->next->next;
    }
    cur_next->next = NULL;
    
    return new_head;
}

//O(1)时间删除链表结点

typedef struct ListNode{
    ListNode* next;
    int val;
}ListNode;

// 4-->5-->7-->3-->NULL  删除7
//       pDel
//      -->3-->3-->NULL
//      -->3   3x   -->NULL
//         |________|

void DeleteNode(ListNode* head,ListNode* pDel)
{
    //无效输入
    if(head==NULL) return;
   
    //正常情况
    if(pDel->next!=NULL)
    {
        //换值,续尾
        ListNode* pDelNext = pDel->next;
        pDel->val = pDelNext->val;
        pDel->next = pDelNext->next;
        
        //删除
        delete pDel;
        pDel = NULL;
    }
    //一个节点
    else if(pDel==head)
    {
        delete pDel;
        pDel = NULL;
        head = NULL;
    }
    //删除的是最后一个
    //顺序删除
    else
    {
      for(ListNode* cur=head;cur->next!=pDel;cur=cur->next);
      cur->next = NULL;
      delete pDel;
      pDel = NULL;
    }
    
    return;
}

//链表倒数第k个节点
typedef struct ListNode{
    ListNode* next;
    int val;
}ListNode;

//快慢指针:
//快指针先走k-1步
//然后一起走

// 4 3  5 6 7 2  k==3
//      p1
// p2
//        p2  p1

ListNode* FindTailK(ListNode* head,int k)
{
    //非法输入
    if(head==NULL || k<1) return NULL;
    
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i=0;i<k-1;++i)
    {
        if(fast->next!=NULL)
          fast = fast->next;
        else  //k值>结点数
          return NULL;
    }
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}

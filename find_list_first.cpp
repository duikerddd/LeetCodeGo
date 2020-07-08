//链表的第一个公共节点

//    2-->3-->4
//    p1
//1-->2-->3-->4
//p2

//解法: 1.计算链表长度 2.让长的链表先走dif(=长-短)步 3.双指针同步走寻找公共节点

int GetLen(ListNode* head)
{
    int len = 0;
    ListNode* cur = head;
    while(cur)
    {
        len++;
        cur = cur->next;
    }
    return len;
}

ListNode* FirstCommonNode(ListNode* p1,ListNode* p2)
{
    //无效输入
    if(p1==NULL || p2==NULL) return NULL;
    
    //1.计算长度
    int len1 = GetLen(p1);
    int len2 = GetLen(p2);
    
    //2.长先走
    int dif = 0;
    if(len2>len1){
        dif = len2-len1;
        while(dif){
          p2=p2->next;
          dif--;
          }
    }
    else if(len2<len1){
        dif = len2-len1;
        while(dif){
          p1=p1->next;
          dif--;
          }
    }
    
    //3.同步走
    while(p1 && p2)
    {
          //找到了
          if(p1==p2)
              return p1;
          p1=p1->next;
          p2=p2->next;
          
    }
    //没找到
    return NULL;
       
}

//合并两个有序链表

//双指针

// 1 4 5 7
// p1
// 2 3 6 8
// p2

//1.比较排序
//2.剩余插入

ListNode* MergeList(ListNode* head1,ListNode* head2)
{
    //非法输入
    if(p1==NULL && p2==NULL) return;
    
    //1.比较排序
    ListNode* p1 = head1;
    ListNode* p2 = head2;
    ListNode* new_list = new ListNode(-1);
    ListNode* cur = new_list;
    while(p1 && p2)
    {
        if(p1->val <= p2->val)
        {
            cur->next = p1;
            p1 = p1->next;
        }
        else
        {
            cur->next = p2;
            p2 = p2->next;
        }
    }
    
   //剩余插入,只有一个链表情况
    cur->next = (l1==NULL?l2:l1);
    return head->next;   
}

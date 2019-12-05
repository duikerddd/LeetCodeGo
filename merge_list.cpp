class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //无效输入
    if(l1==NULL && l2==NULL)
        return NULL;
             
    ListNode* head = new ListNode(-1);
    ListNode* cur = head;
    //比较插入
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val <= l2->val)
         {
             cur->next = l1;
             l1 = l1->next;
         }   
         else
         {
             cur->next = l2;
             l2 = l2->next;
         }
         cur = cur->next;
    }
    
    //剩余插入,只有一个链表情况
    cur->next = (l1==NULL?l2:l1);
    return head->next;   

    }
};

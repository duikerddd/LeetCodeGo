/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //双指针---前后指针  
    //1.head前面插入一个pre,start和end指向pre
    //2.start先走n步,然后齐头并进
    //3.这样end肯定就是倒数的结点了,让start少走一步,就是删除的父节点了,但是有种特殊情况:start后面是空,说明第一个就是删除的点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head->next == NULL){
                return NULL;
            }
            ListNode* pre = new ListNode(0);
            pre->next = head;
            ListNode* start = pre,* end = pre;
            while(n!=0)
            {   
                start = start->next;
                n--;
            }
            //先判断是否第一个结点就是要删除的
             if(start->next == NULL)
            {
                start=head->next;
                delete head;
                return start;
            }
            //两指针齐头并进
            while(start->next!=NULL)
            {
                start = start->next;
                end = end->next;
            }
           
            ListNode* tmp = end->next->next;
            delete end->next;
            end->next = tmp;
            return head;
            
    }
};

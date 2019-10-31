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
    //链表为空 === 退出
    //链表只有一个 ===  判断是否为目标值
    //链表两个以上,计算长度,计算结点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head==NULL) return head;
            if(head->next==NULL) {
                if(n==1)
                {
                    head = NULL;
                    return head;
                }
                return head;
            }
        
            int len = 0;
            ListNode* cur = head;
            while(cur!=NULL)
            {
                ++len;
                cur=cur->next;
            }
        
            cur = head;
            //父节点
            int dif = len - n -1;
            if(dif<0)
            {
                ListNode* tmp=cur->next;
                delete head;
                head = tmp;
                return head;
            }
            for(int i=0;i<dif;++i)
            {
                cur = cur->next;
            }
            ListNode* tmp=cur->next->next;
            delete cur->next;
            cur->next = tmp;
            return head;
    }
};
